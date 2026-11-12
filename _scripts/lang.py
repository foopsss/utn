import argparse
import functools
import os
import shutil
import subprocess
import sys
import textwrap

from abc import ABC, abstractmethod
from pathlib import Path

from _utils import check_if_tools_installed, draw_line, get_repo_root


class AbstractBackend(ABC):
    def __init__(self, filename: str, path: str, debug_build: bool) -> None:
        self.filename = filename
        self.path = Path(path)
        self.debug_build = debug_build

    def _resolve_tool(self, env_var: str, admitted_tools: list[str]) -> str:
        env_tool = os.getenv(env_var, None)

        if env_tool is None:
            # Si el usuario no especifica la herramienta
            # que desea utilizar, se tomará la primera
            # de la lista de herramientas admitidas
            # para un lenguaje en específico, y que
            # además esté instalada en el sistema.
            available_tool = None
            for tool in admitted_tools:
                if shutil.which(tool):
                    available_tool = tool
                    return available_tool

            if available_tool is None:
                raise OSError(
                    "¡No hay ninguna herramienta instalada para el archivo"
                    " indicado!"
                    "\nLas herramientas admitidas para el archivo son:"
                    f" {admitted_tools}."
                )

        # El comportamiento por defecto es utilizar
        # el compilador que suministra el usuario.
        check_if_tools_installed([env_tool])
        return env_tool

    def _get_binary_path(self) -> Path:
        ext = ".exe" if os.name == "nt" else ""
        return self.path / f"{self.filename}{ext}"

    def _run_compiler(self, command: list[str]) -> None:
        try:
            subprocess.run(
                command,
                capture_output=True,
                text=True,
                check=True,
                cwd=self.path,
            )
        except subprocess.CalledProcessError as err:
            if err.stderr:
                err_msg = err.stderr
            else:
                err_msg = err.stdout

            print(f"{err_msg}")
            sys.exit(1)

    @property
    @abstractmethod
    def admitted_compilers(self) -> list[str]:
        pass

    @property
    @abstractmethod
    def admitted_debuggers(self) -> list[str]:
        pass

    @property
    def file_extension(self) -> str:
        pass

    @property
    @functools.cache
    def compiler(self) -> str:
        return self._resolve_tool(
            env_var="COMPILER", admitted_tools=self.admitted_compilers
        )

    @property
    def default_compiler_flags(self) -> list[str]:
        pass

    @property
    @functools.cache
    def used_compiler_flags(self) -> list[str]:
        override_flags = os.getenv("OVERRIDE_FLAGS", None)
        add_flags = os.getenv("ADD_FLAGS", "")

        if override_flags is not None:
            flags = override_flags.split()
        else:
            flags = self.default_compiler_flags + add_flags.split()

        return flags

    @property
    @functools.cache
    def debugger(self) -> str:
        return self._resolve_tool(
            env_var="DEBUGGER", admitted_tools=self.admitted_debuggers
        )

    @property
    def debug_flag(self) -> str:
        pass

    def compile(self) -> None:
        command = (
            [self.compiler]
            + [f"{self.filename}{self.file_extension}"]
            + self.used_compiler_flags
        )

        if self.debug_build:
            command.insert(1, self.debug_flag)

        self._run_compiler(command)

    def execute(self) -> None:
        self.compile()
        exec_path = self._get_binary_path().name

        if self.debug_build:
            command = [self.debugger, exec_path]
        else:
            command = (
                [f"./{exec_path}"] if os.name != "nt" else [f"{exec_path}"]
            )

        subprocess.run(command, check=True, cwd=str(self.path))

    def remove_files(self) -> None:
        # Implementación compartida, pero parcial, del
        # método de borrado para todos los backends.
        # Posiblemente deba ser sobreescrita por las
        # clases herederas para añadir más funcionalidad
        # de borrado o redefinirla por completo.
        full_exec_path = self._get_binary_path()

        if full_exec_path.exists() and full_exec_path.is_file():
            full_exec_path.unlink()
            print("Ejecutable principal eliminado.")
        else:
            print(
                "No se pudo encontrar ningún ejecutable llamado"
                f" '{full_exec_path.name}' para borrar."
            )


class PascalBackend(AbstractBackend):
    @property
    def admitted_compilers(self) -> list[str]:
        return ["fpc"]

    @property
    def admitted_debuggers(self) -> list[str]:
        return ["gdb"]

    @property
    def file_extension(self) -> str:
        return ".pas"

    @property
    def default_compiler_flags(self) -> list[str]:
        return []

    @property
    def debug_flag(self) -> str:
        return "-g"

    def remove_files(self) -> None:
        super().remove_files()
        # Remoción de TODOS los archivos con extensión ".o" y
        # extensión ".ppu" del directorio actual hacia abajo.
        # Este enfoque es medio nuclear pero cubre el caso de
        # borrar los objetos de la librería "functions.pas".
        cwd = Path(".")
        files_to_delete = []
        deleted_files_amount = 0

        for extension in ["*.o", "*.ppu"]:
            files_to_delete += list(cwd.rglob(extension))

        for file in files_to_delete:
            file.unlink()
            deleted_files_amount += 1

        if deleted_files_amount == len(files_to_delete):
            print("Archivos residuales de la compilación eliminados.")
        else:
            print(
                "No se han podido borrar uno o más archivos residuales"
                " de la compilación."
            )


class CBackend(AbstractBackend):
    @property
    def admitted_compilers(self) -> list[str]:
        return ["gcc", "clang"]

    @property
    def admitted_debuggers(self) -> list[str]:
        return ["gdb", "lldb"]

    @property
    def file_extension(self) -> str:
        return ".c"

    @property
    def default_compiler_flags(self) -> list[str]:
        # Únicamente se permiten compiladores que compartan
        # los mismos flags (es decir, aquellos que buscan ser
        # compatibles con GCC), así que no debería haber
        # problemas con especificarlos de esta forma.
        return [
            "-fdiagnostics-color=always",
            "-std=c23",
            "-O2",
            "-Wall",
            "-Wextra",
            "-Werror",
            "-Wpedantic",
            "-pedantic-errors",
            "-Wstrict-aliasing=2",
            "-Wconversion",
            "-Wshadow",
            "-o",
            self.filename,
        ]

    @property
    def debug_flag(self) -> str:
        return "-g"


LanguageBackends = {
    ".pas": PascalBackend,
    ".c": CBackend,
}


def parse_cli_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Permite compilar y ejecutar código escrito en distintos"
        " lenguajes, así como limpiar los archivos resultantes del proceso de"
        " compilación."
    )

    parser.add_argument(
        "file",
        action="store",
        help="Archivo de código fuente a compilar. Debe incluir la extensión"
        " del archivo.",
    )

    parser.add_argument(
        "-d",
        "--debug",
        action="store_true",
        help="Permite especificar si la build a producir debe tener símbolos"
        " de depuración. Implica que --e/-execute ejecute el programa con un"
        " depurador.",
    )

    exclude_group = parser.add_mutually_exclusive_group(required=True)
    exclude_group.add_argument(
        "-c",
        "--compile",
        action="store_true",
        help="Permite especificar que solo se desea compilar el código"
        " indicado.",
    )

    exclude_group.add_argument(
        "-e",
        "--execute",
        action="store_true",
        help="Permite especificar que se desea compilar y ejecutar el código."
        " Si se especifica junto a -d/--debug implica ejecutar el programa"
        " con un depurador.",
    )

    exclude_group.add_argument(
        "-r",
        "--remove",
        action="store_true",
        help="Permite especificar que se desean remover los archivos obtenidos"
        " como producto del proceso de compilación de un programa dado.",
    )

    args = parser.parse_args()
    if args.remove and args.debug:
        parser.error(
            "Los parámetros --remove y --debug no se pueden utilizar juntos."
        )
        sys.exit(1)

    return args


def show_compile_info(backend: AbstractBackend) -> None:
    flags_str = (
        " ".join(backend.used_compiler_flags)
        if backend.used_compiler_flags
        else "ninguno"
    )

    raw_lines = [
        f"Archivo: {backend.filename}{backend.file_extension}",
        f"Ubicación: {backend.path}",
        f"Compilador utilizado: {backend.compiler}",
        f"Parámetros de compilación: {flags_str}",
    ]

    # Obtención del ancho de la ventana de terminal actual.
    # Se utiliza un valor por defecto de 80 caracteres en caso de fallo.
    terminal_columns = shutil.get_terminal_size(fallback=(80, 24)).columns

    # Determinación de la máxima longitud de línea posible con
    # las dimensiones de terminal actuales. Se dejan 4 dígitos de
    # espacio al final con la finalidad de tener algo de espacio
    # para que los bordes se muestren bien.
    max_text_width = terminal_columns - 4

    # Ajuste de líneas que exceden el ancho de la terminal.
    wrapped_lines = []
    for line in raw_lines:
        # textwrap.wrap se encarga de dividir strings largos sin cortar
        # palabras.
        wrapped = textwrap.wrap(line, width=max_text_width)
        wrapped_lines.extend(wrapped)

    # Hay que averiguar cuál es la línea más larga, tras el ajuste
    # para que las líneas quepan dentro de las dimensiones de la
    # terminal.
    max_length = max(len(line) for line in wrapped_lines)

    # Impresión de la información deseada, propiamente formateada.
    print(f"╔{'═' * (max_length + 2)}╗")
    for line in wrapped_lines:
        print(f"║ {line.ljust(max_length)} ║")
    print(f"╚{'═' * (max_length + 2)}╝")


def main() -> None:
    check_if_tools_installed(["git"])
    args = parse_cli_arguments()
    cwd = get_repo_root()
    matches = list(cwd.rglob(args.file))

    if len(matches) == 0:
        print(
            "No se ha podido encontrar ningún archivo con el nombre"
            " especificado."
        )
        sys.exit(1)
    elif len(matches) > 1:
        print("Se ha encontrado más de un archivo con el nombre especificado.")
        print("Los archivos encontrados son:")
        print("")

        for file in matches:
            match_path = str(file.absolute())
            print(f"* {match_path}")

        print("")
        print(
            "Por favor, renombre los archivos para eliminar la ambiguedad"
            " existente y ejecute el script de nuevo."
        )
        sys.exit(1)

    if len(matches[0].suffixes) > 1:
        print(
            "Se está trabajando con un archivo que tiene dos o más"
            " extensiones."
        )
        print(
            "Todas las extensiones a excepción de la última serán ignoradas."
        )
        draw_line()

    available_backend = LanguageBackends.get(matches[0].suffix, None)
    if available_backend is None:
        print(
            "Se ha proporcionado un archivo que el script no sabe cómo"
            " tratar."
        )
        sys.exit(1)

    filename_stem = matches[0].stem
    file_parent_path = str(matches[0].parent.absolute())
    is_debug_build = bool(args.debug)

    lang_file = available_backend(
        filename=filename_stem,
        path=file_parent_path,
        debug_build=is_debug_build,
    )

    if args.compile or args.execute:
        show_compile_info(lang_file)

    if args.compile:
        lang_file.compile()
    elif args.execute:
        lang_file.execute()
    elif args.remove:
        lang_file.remove_files()


if __name__ == "__main__":
    main()

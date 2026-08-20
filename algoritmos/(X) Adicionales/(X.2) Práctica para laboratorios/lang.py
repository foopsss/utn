import argparse
import os
import subprocess
import sys

from abc import ABC, abstractmethod
from pathlib import Path


def draw_line() -> None:
    line = "=" * 100
    print(line)


class AbstractBackend(ABC):
    def __init__(self, filename: str, path: str, debug_build: bool):
        self.filename = filename
        self.path = path
        self.debug_build = debug_build

    def _get_binary_name(self):
        if os.name != "nt":
            return f"./{self.filename}"
        else:
            return f"{self.filename}.exe"

    def execute(self):
        self.compile()
        draw_line()
        binary_name = self._get_binary_name()
        command = ["gdb", binary_name] if self.debug_build else binary_name
        subprocess.run(command, check=True, cwd=self.path)

    def remove_files(self):
        # Implementación compartida, pero parcial, del
        # método de borrado para todos los backends.
        # Posiblemente deba ser sobreescrita por las
        # clases herederas para añadir más funcionalidad
        # de borrado o redefinirla por completo.
        binary_name = self._get_binary_name()
        full_exec_path = self.path + "/" + binary_name

        if os.path.exists(full_exec_path):
            os.remove(full_exec_path)
            print("Ejecutable principal eliminado.")
        else:
            print(
                "No se pudo encontrar ningún ejecutable llamado"
                f" {binary_name} para borrar."
            )

    @abstractmethod
    def compile(self):
        pass


class PascalBackend(AbstractBackend):
    def compile(self):
        command = ["fpc", f"{self.filename}.pas"]

        if self.debug_build:
            command.insert(1, "-g")

        subprocess.run(command, check=True, cwd=self.path)

    def remove_files(self):
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
    def compile(self):
        command = ["gcc", f"{self.filename}.c", "-o", self.filename]

        if self.debug_build:
            command.insert(1, "-g")

        print(f"Compilando: {self.filename}.c")
        print(f"Ubicación: {self.path}")
        subprocess.run(command, check=True, cwd=self.path)


language_backends = {
    ".pas": PascalBackend,
    ".c": CBackend,
}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Permite compilar y ejecutar código escrito en Pascal y"
        " en C, así como limpiar los archivos resultantes del proceso de"
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
        " de depuración. Implica que --e/-execute ejecute el programa con GDB"
        " para depurarlo.",
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
        " con GDB para depurarlo.",
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

    cwd = Path(".")
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

    available_backend = language_backends.get(matches[0].suffix, None)
    if available_backend is None:
        print(
            "Se ha proporcionado un archivo que el script no sabe cómo"
            " tratar."
        )
        sys.exit(1)
    else:
        filename_stem = matches[0].stem
        file_parent_path = str(matches[0].parent.absolute())
        is_debug_build = bool(args.debug)

        lang_file = available_backend(
            filename=filename_stem,
            path=file_parent_path,
            debug_build=is_debug_build,
        )

        if args.compile:
            lang_file.compile()
        elif args.execute:
            lang_file.execute()
        elif args.remove:
            lang_file.remove_files()

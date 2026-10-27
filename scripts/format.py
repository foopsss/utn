import argparse
import subprocess
import sys

from pathlib import Path

from _utils import check_if_tools_installed, get_repo_root

formatters = {
    "black": ["black"],
    "clang-format": ["clang-format", "-i"],
}

extension_associations = {
    ".c": "clang-format",
    ".h": "clang-format",
    ".py": "black",
}


def parse_cli_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Programa para formatear los archivos de código del"
        " repositorio."
    )
    exclude_group = parser.add_mutually_exclusive_group(required=True)

    exclude_group.add_argument(
        "-a",
        "--all",
        action="store_true",
        help="Indica que se desean formatear todos los archivos de código del"
        " repositorio.",
    )

    exclude_group.add_argument(
        "-c",
        "--changed",
        action="store_true",
        help="Indica que se desean formatear solo los archivos de código del"
        " repositorio que hayan cambiado, ya sea por creación o modificación.",
    )

    return parser.parse_args()


def run_formatter(file: Path) -> None:
    formatter = extension_associations.get(file.suffix, None)
    format_cmd = formatters.get(formatter, None)

    if format_cmd is None:
        raise RuntimeError(
            "No hay un formateador registrado para la extensión"
            f" {file.suffix}."
        )

    try:
        subprocess.run(format_cmd + [file], capture_output=True, check=True)
    except subprocess.CalledProcessError as err:
        print(f"No se pudo ejecutar el formateador: {err.cmd}")
        print(f"Código de salida: {err.returncode}")


def fetch_change_list(repo_root: Path) -> list[Path]:
    try:
        result = subprocess.run(
            ["git", "status", "--porcelain", "-z"],
            cwd=repo_root,
            capture_output=True,
            check=True,
            text=True,
        )
        raw_lines = [line for line in result.stdout.split("\x00") if line]

        change_list = []
        for line in raw_lines:
            if "D" in line[:2]:
                continue

            file = repo_root / line[3:]
            if file.suffix in extension_associations:
                change_list.append(file)

        return change_list
    except subprocess.CalledProcessError as err:
        print("No se pudo obtener la lista de cambios de git.")
        print(f"Error encontrado: {err.output}")
        sys.exit(1)


def main() -> None:
    check_if_tools_installed(["git"] + list(formatters.keys()))
    cli_args = parse_cli_arguments()

    # "format.py" reside en "scripts/", así que es
    # necesario encontrar la raíz del repositorio.
    repo_root = get_repo_root()

    if cli_args.all:
        for ext in list(extension_associations.keys()):
            for file in repo_root.rglob(f"*{ext}"):
                run_formatter(file)
    elif cli_args.changed:
        changed_files = fetch_change_list(repo_root)
        for file in changed_files:
            run_formatter(file)


if __name__ == "__main__":
    main()

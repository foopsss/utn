import shutil
import subprocess
import sys

from pathlib import Path


def draw_line() -> None:
    line = "=" * 100
    print(line)


def check_if_tools_installed(tools: list[str]) -> None:
    for tool in tools:
        if not shutil.which(tool):
            raise RuntimeError(
                f"{tool} no está instalado en el sistema, o no se encuentra"
                " añadido a la variable de entorno PATH."
            )


def get_repo_root() -> Path:
    try:
        root_str = subprocess.run(
            ["git", "rev-parse", "--show-toplevel"],
            capture_output=True,
            text=True,
            check=True,
        )
        return Path(root_str.stdout.strip())
    except subprocess.CalledProcessError:
        print("¡No se pudo obtener la raíz del repositorio!")
        sys.exit(1)

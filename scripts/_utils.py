import subprocess
import sys

from pathlib import Path


def draw_line() -> None:
    line = "=" * 100
    print(line)


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

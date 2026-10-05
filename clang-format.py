import subprocess

from pathlib import Path

if __name__ == "__main__":
    walk_dir = Path.cwd()
    for ext in ["*.c", "*.cpp", "*.h", "*.hpp"]:
        for file in walk_dir.rglob(ext):
            subprocess.run(["clang-format", "-i", f"{file}"])

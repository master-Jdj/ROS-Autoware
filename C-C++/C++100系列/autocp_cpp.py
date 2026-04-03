import argparse
import sys
from pathlib import Path

#自动生成CppXX.cpp文件脚本
def cpp_path(base_dir: Path, code: int) -> Path:
    return base_dir / f"Cpp{code}.cpp"


def run_range(base_dir: Path, start: int, end: int) -> int:
    if start > end:
        print("Error: Invalid range: start must be <= end.", file=sys.stderr)
        return 1

    for code in range(start, end + 1):
        target = cpp_path(base_dir, code)
        if target.exists():
            print(f"Skip existing: {target}")
            continue

        target.write_text("", encoding="utf-8")
        print(f"Created: {target}")

    return 0


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Generate empty CppXX.cpp files in a numeric range."
    )
    parser.add_argument("range", nargs="*", help="Start and end, e.g. 15 20")
    parser.add_argument("--dir", type=str, default=".", help="Target directory.")

    args = parser.parse_args()
    base_dir = Path(args.dir)

    if len(args.range) == 2:
        try:
            start = int(args.range[0])
            end = int(args.range[1])
        except ValueError:
            print("Error: range must be two integers, e.g. 15 20", file=sys.stderr)
            return 1
        return run_range(base_dir, start, end)

    if len(args.range) == 0:
        raw = input("Input range (start end), e.g. 15 20: ").strip()
        parts = raw.split()
        if len(parts) != 2:
            print("Error: please input exactly two integers.", file=sys.stderr)
            return 1
        try:
            start = int(parts[0])
            end = int(parts[1])
        except ValueError:
            print("Error: range must be two integers, e.g. 15 20", file=sys.stderr)
            return 1
        return run_range(base_dir, start, end)

    print("Error: invalid arguments. Use: python gen_next_cpp.py 15 20", file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())

import sys
import subprocess
import time
from HashTable import HashTable


def clear_screen() -> None:
    subprocess.run(["clear"])


def main(args: list[str]) -> None:
    table = HashTable()

    for word in args:
        table.add(word)

    while True:
        clear_screen()

        print("====== HASH TABLE ======")
        print("1. Display")
        print("2. Add")
        print("3. Delete")
        print("0. Quit")

        choice = input("\nChoice: ").strip()

        if choice == "1":
            table.display()
            input("\nPress Enter to continue...")

        elif choice == "2":
            word = input("Word: ").strip()
            table.add(word)
            input("\nWord added. Press Enter to continue...")

        elif choice == "3":
            word = input("Word: ").strip()
            table.delete(word)
            input("\nPress Enter to continue...")

        elif choice == "0":
            clear_screen()
            print("👋 Bye!")
            time.sleep(2)
            clear_screen()
            sys.exit()

        else:
            print("\n❌ Invalid choice.", file=sys.stderr)
            input("Press Enter to continue...")


if __name__ == "__main__":
    try:
        main(sys.argv[1:])
    except Exception:
        print("Error")
        sys.exit()
    except KeyboardInterrupt:
        print("Keyboard interrupt")
        sys.exit()

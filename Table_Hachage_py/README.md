***This project was created by Jusinho.***

# Python Hash Table

This project implements a simple hash table in Python with an interactive menu to add, delete, display, and search for words.

## Project Structure

- `hachage.py`: main program
- `HashTable/hashTable.py`: hash table implementation
- `Makefile`: convenient commands to run, clean, and lint the project
- `requirements-dev.txt`: development dependencies (`flake8`, `mypy`, `build`)

## Prerequisites

- Python 3
- `make`

## Installation

```bash
make install
```

This command creates a virtual environment `.venv` and installs development dependencies.

## Running

```bash
make run
```

## Code Checks

```bash
make lint
```

This command runs the following checks:

- `flake8`: Python style checks
- `mypy`: static type checking

## Cleanup

```bash
make clean
```

This command removes Python cache files and build artifacts.

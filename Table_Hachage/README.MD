***This project is realised by Jusinho***

# Hash Table in C

A simple implementation of a **hash table** in C using **separate chaining** (linked lists) to resolve collisions.

## Features

- Add a new word
- Delete a word
- Display the hash table
- Collision handling using linked lists
- Memory management (`malloc` / `free`)
- Interactive menu

---

## Project Structure

```
.
├── hachage.c       # Main program
├── function.c      # Hash table functions
├── Hachage.h       # Header file
├── Makefile
└── README.md
```

---

## Data Structure

Each bucket of the hash table points to a linked list.

```
table
+-----+      +---------+      +---------+
|  0  | ---> | Hello   | ---> | World   | ---> NULL
+-----+
|  1  | ---> NULL
+-----+
|  2  | ---> | Apple   | ---> NULL
+-----+
```

---

## Hash Function

The hash function computes the sum of the ASCII values of all characters in the word.

```c
index = TotalAscii(word) % SIZE;
```

---

## Compilation

Compile the project using:

```bash
make
```

---

## Run

Without initial data:

```bash
./hash
```

With initial words:

```bash
./hash Hello World Apple Banana
```

---

## Menu

```
1. Display
2. Add
3. Delete
0. Quit
```

---

## Example

```
Choice: 2
Word:
-> Hello

Choice: 2
Word:
-> World

Choice: 1

TABLE DE HACHAGE

[0] Hello
[1] VIDE
[2] World
...
```

---

## Memory Check

Run Valgrind:

```bash
make valgrind
```

or

```bash
valgrind \
    --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    ./hash
```

---

## Complexity

| Operation | Average | Worst Case |
|-----------|---------|------------|
| Insert    | O(1)    | O(n)       |
| Search    | O(1)    | O(n)       |
| Delete    | O(1)    | O(n)       |

---

## Author

Made as a learning project to understand:

- Hash tables
- Linked lists
- Dynamic memory allocation
- Collision handling
- C programming
class HashTable:
    def __init__(self, size: int = 7) -> None:
        self.size = size
        self.table: list[list[str]] = [[] for _ in range(size)]

    def total_ascii(self, word: str) -> int:
        return sum(ord(c) for c in word.lower())

    def add(self, word: str) -> None:
        index = self.total_ascii(word) % self.size

        if word not in self.table[index]:
            self.table[index].append(word)
        else:
            print(f'"{word}" existe déjà.')

    def delete(self, word: str) -> None:
        index = self.total_ascii(word) % self.size

        if word in self.table[index]:
            self.table[index].remove(word)
        else:
            print(f'"{word}" est introuvable.')

    def search(self, word: str) -> bool:
        index = self.total_ascii(word) % self.size
        return word in self.table[index]

    def display(self) -> None:
        print("\nTABLE DE HACHAGE")
        for i, bucket in enumerate(self.table):
            if bucket:
                print(f"[{i}] {' -> '.join(bucket)}")
            else:
                print(f"[{i}] VIDE")

class Book:
    def __init__(self, name, author, id, count):
        self.name = name
        self.author = author
        self.id = id
        self.count = count
        self.total_count = count

    def borrow(self):
        if self.count > 0:
            self.count -= 1
            print(f"The {self.name} has been borrowed!")
        else:
            print(f"{self.name} is not available for borrowing.")

    def return_book(self):
        if self.count == self.total_count:
            print(f"{self.name} was not borrowed.")
        else:
            self.count += 1
            print(f"{self.name} has been returned.")


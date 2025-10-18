class Book:
    def __init__(self, title, author, ISBN):
        self.title = title
        self.author = author
        self.ISBN = ISBN
        self.is_borrowed = False

    def borrow(self):
        if not self.is_borrowed:
            self.is_borrowed = True
            print(f"'{self.title}' has been borrowed.")
        else:
            print(f"'{self.title}' is already borrowed!")

    def return_book(self):
        if self.is_borrowed:
            self.is_borrowed = False
            print(f"'{self.title}' has been returned.")
        else:
            print(f"'{self.title}' was not borrowed.")


class Member:
    def __init__(self, name, memberID):
        self.name = name
        self.memberID = memberID
        self.borrowed_books = []

    def register(self):
        print(f"Member '{self.name}' with ID {self.memberID} registered.")

    def borrow_book(self, book: Book):
        if not book.is_borrowed:
            book.borrow()
            self.borrowed_books.append(book)
        else:
            print(f"Sorry {self.name}, the book '{book.title}' is not available.")

    def return_book(self, book: Book):
        if book in self.borrowed_books:
            book.return_book()
            self.borrowed_books.remove(book)
        else:
            print(f"{self.name} doesn’t have '{book.title}' borrowed.")


class Library:
    def __init__(self, name):
        self.name = name
        self.books = []

    def addBook(self, book: Book):
        self.books.append(book)
        print(f"'{book.title}' added to {self.name} library.")

    def removeBook(self, book: Book):
        if book in self.books:
            self.books.remove(book)
            print(f"'{book.title}' removed from {self.name} library.")
        else:
            print(f"'{book.title}' not found in library.")


FirstLib = Library("Marzdaran")


b1 = Book("Clean Code", "Robert C. Martin", "9780132350884")

FirstLib.addBook(b1)

m1 = Member("hamed" , "123456")
m1.register()



m1.borrow_book(b1)
for book in m1.borrowed_books:
    print(book.title)




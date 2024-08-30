#include <iostream>
#include <string>


using namespace std;


// Define the Book class
class Book {
public:
   // Constructor
   Book(string title = "", string author = "", int year = 0)
       : title(title), author(author), year(year) {}


   // Set book details
   void setDetails(const string& title, const string& author, int year) {
       this->title = title;
       this->author = author;
       this->year = year;
   }


   // Getters
   string getTitle() const { return title; }
   string getAuthor() const { return author; }
   int getYear() const { return year; }


   // Display book details
   void display() const {
       cout << "Title: " << title << endl;
       cout << "Author: " << author << endl;
       cout << "Year: " << year << endl;
   }


private:
   string title;
   string author;
   int year;
};


// Define the Library class
class Library {
public:
   Library() : bookCount(0) {}


   // Add a book to the library
   void addBook(const Book& book) {
       if (bookCount < MAX_BOOKS) {
           books[bookCount] = book;
           bookCount++;
           cout << "Book added successfully!" << endl;
       } else {
           cout << "Library is full! Cannot add more books." << endl;
       }
   }


   // Display all books in the library
   void displayAllBooks() const {
       if (bookCount == 0) {
           cout << "No books in the library." << endl;
           return;
       }
       cout << "Books in the library:" << endl;
       for (int i = 0; i < bookCount; ++i) {
           books[i].display();
           cout << "----------" << endl;
       }
   }


   // Search for a book by title
   void searchBookByTitle(const string& title) const {
       for (int i = 0; i < bookCount; ++i) {
           if (books[i].getTitle() == title) {
               cout << "Book found!" << endl;
               books[i].display();
               return;
           }
       }
       cout << "Book not found!" << endl;
   }


private:
   static const int MAX_BOOKS = 100; // Maximum number of books
   Book books[MAX_BOOKS];            // Array to store books
   int bookCount;                    // Number of books currently in the library
};


// Main function to drive the program
int main() {
   Library library;
   int choice;
   string title, author;
   int year;


   do {
       // Display menu
       cout << "Library Management System" << endl;
       cout << "1. Add Book" << endl;
       cout << "2. Display All Books" << endl;
       cout << "3. Search Book by Title" << endl;
       cout << "4. Exit" << endl;
       cout << "Enter your choice: ";
       cin >> choice;
       cin.ignore(); // Ignore newline character left by cin


       switch (choice) {
           case 1:
               // Add Book
               cout << "Enter title: ";
               getline(cin, title);
               cout << "Enter author: ";
               getline(cin, author);
               cout << "Enter year: ";
               cin >> year;
               cin.ignore(); // Ignore newline character left by cin
               library.addBook(Book(title, author, year));
               break;


           case 2:
               // Display All Books
               library.displayAllBooks();
               break;


           case 3:
               // Search Book by Title
               cout << "Enter title of the book to search: ";
               getline(cin, title);
               library.searchBookByTitle(title);
               break;


           case 4:
               // Exit
               cout << "Exiting the program." << endl;
               break;


           default:
               cout << "Invalid choice. Please try again." << endl;
               break;
       }


       cout << endl;


   } while (choice != 4);


   return 0;
}

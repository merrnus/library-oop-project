#include "Library.h"
#include <iostream>

int main() {
    std::cout << "=== Library Management System ===" << "\n\n";
    
    // Create authors
    Author author1("George Orwell", "UK");
    Author author2("J.K. Rowling", "UK");
    Author author3("Haruki Murakami", "Japan");
    
    std::cout << "Authors created:\n";
    std::cout << "- " << author1 << "\n";
    std::cout << "- " << author2 << "\n";
    std::cout << "- " << author3 << "\n\n";
    
    // Create books
    Book book1("1984", author1, 1949, 5);
    Book book2("Animal Farm", author1, 1945, 3);
    Book book3("Harry Potter", author2, 1997, 10);
    Book book4("Norwegian Wood", author3, 1987, 2);
    
    // Create library
    Library library("Central Library");
    std::cout << "Created: " << library << "\n\n";
    
    // Add books
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    
    // Display all books
    library.displayBooks();
    
    // Test copy constructor
    std::cout << "Testing copy constructor:\n";
    Book book5 = book1;  // Copy constructor
    std::cout << "Copied book: " << book5 << "\n\n";
    
    // Test copy assignment
    std::cout << "Testing copy assignment:\n";
    Book book6("Temp", author3, 2000, 1);
    book6 = book2;  // Copy assignment
    std::cout << "Assigned book: " << book6 << "\n\n";
    
    // Find books by author
    std::cout << "Finding books by George Orwell:\n";
    auto orwellBooks = library.findBooksByAuthor("George Orwell");
    for (const auto& book : orwellBooks) {
        std::cout << "- " << book << "\n";
    }
    std::cout << "\n";
    
    // Remove a book
    library.removeBook("1984");
    library.displayBooks();
    
    // Try removing non-existent book
    library.removeBook("Non-existent Book");
    
    std::cout << "\n=== Program finished ===" << "\n";
    return 0;
}
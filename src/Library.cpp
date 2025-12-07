#include "Library.h"
#include <algorithm>

// Constructor
Library::Library(const std::string& name) : name(name) {}

// Add book
void Library::addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Added: " << book.getTitle() << " to " << name << "\n";
}

// Remove book by title
bool Library::removeBook(const std::string& title) {
    auto it = std::find_if(books.begin(), books.end(),
        [&title](const Book& book) {
            return book.getTitle() == title;
        });
    
    if (it != books.end()) {
        std::cout << "Removed: " << title << " from " << name << "\n";
        books.erase(it);
        return true;
    }
    
    std::cout << "Book not found: " << title << "\n";
    return false;
}

// Find books by author name
std::vector<Book> Library::findBooksByAuthor(const std::string& authorName) const {
    std::vector<Book> result;
    
    for (const auto& book : books) {
        if (book.getAuthor().getName() == authorName) {
            result.push_back(book);
        }
    }
    
    return result;
}

// Display all books
void Library::displayBooks() const {
    std::cout << "\n=== " << name << " ===" << "\n";
    std::cout << "Total books: " << books.size() << "\n\n";
    
    for (const auto& book : books) {
        std::cout << "- " << book << "\n";
    }
    std::cout << "\n";
}

// Getters
std::string Library::getName() const {
    return name;
}

int Library::getBookCount() const {
    return books.size();
}

// operator
std::ostream& operator<<(std::ostream& os, const Library& library) {
    os << library.name << " (Books: " << library.books.size() << ")";
    return os;
}
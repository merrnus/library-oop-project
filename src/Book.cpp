#include "Book.h"

// Constructor
Book::Book(const std::string& title, const Author& author, int year, int stock)
    : title(title), author(author), year(year), stock(stock) {}

// Copy constructor (Rule of Three)
Book::Book(const Book& other)
    : title(other.title), author(other.author), year(other.year), stock(other.stock) {
    std::cout << "Book copy constructor called for: " << title << "\n";
}

// Copy assignment operator (Rule of Three)
Book& Book::operator=(const Book& other) {
    if (this != &other) {
        title = other.title;
        author = other.author;
        year = other.year;
        stock = other.stock;
        std::cout << "Book copy assignment called for: " << title << "\n";
    }
    return *this;
}

// Destructor (Rule of Three)
Book::~Book() {
    std::cout << "Book destructor called for: " << title << "\n";
}

// Getters
std::string Book::getTitle() const {
    return title;
}

const Author& Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

int Book::getStock() const {
    return stock;
}

// Setter
void Book::setStock(int newStock) {
    stock = newStock;
}

// operator
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "\"" << book.title << "\" by " << book.author 
       << " (" << book.year << ") - Stock: " << book.stock;
    return os;
}
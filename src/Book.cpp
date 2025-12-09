#include "../include/Book.h"

// Constructor - calls Item constructor!
Book::Book(const std::string& title, const Author& author, int year, int stock)
    : Item(title, year), author(author), stock(stock) {
    std::cout << "Book constructor called for: " << title << "\n";
}

// Copy constructor (M1'den)
Book::Book(const Book& other)
    : Item(other.title, other.year), author(other.author), stock(other.stock) {
    std::cout << "Book copy constructor called for: " << title << "\n";
}

// Copy assignment (M1'den)
Book& Book::operator=(const Book& other) {
    std::cout << "Book copy assignment called for: " << other.title << "\n";
    if (this != &other) {
        // Item part
        title = other.title;
        year = other.year;
        // Book part
        author = other.author;
        stock = other.stock;
    }
    return *this;
}

// Destructor (M1'den)
Book::~Book() {
    std::cout << "Book destructor called for: " << title << "\n";
}

// Virtual function implementations
void Book::display() const {
    std::cout << "Book: \"" << title << "\" by " << author 
              << ", Year: " << year << ", Stock: " << stock;
}

Book* Book::clone() const {
    return new Book(*this);
}

std::string Book::getType() const {
    return "Book";
}

double Book::calculateLateFee(int days) const {
    // Books: 0.5 lei per day
    return days * 0.5;
}

// Getters (M1'den)
const Author& Book::getAuthor() const {
    return author;
}

int Book::getStock() const {
    return stock;
}

void Book::setStock(int newStock) {
    stock = newStock;
}
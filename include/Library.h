#pragma once
#include "Book.h"
#include <vector>
#include <string>
#include <iostream>

class Library {
private:
    std::string name;
    std::vector<Book> books;  // Composition!

public:
    // Constructor
    Library(const std::string& name);
    
    // Public functions (3 non-trivial)
    void addBook(const Book& book);
    bool removeBook(const std::string& title);
    std::vector<Book> findBooksByAuthor(const std::string& authorName) const;
    
    // Display
    void displayBooks() const;
    
    // Getters
    std::string getName() const;
    int getBookCount() const;
    
    // operator
    friend std::ostream& operator<<(std::ostream& os, const Library& library);
};
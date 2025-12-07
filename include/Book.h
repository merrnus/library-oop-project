#pragma once
#include "Author.h"
#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    Author author;  // Composition!
    int year;
    int stock;

public:
    // Constructor
    Book(const std::string& title, const Author& author, int year, int stock);
    
    // Rule of Three
    Book(const Book& other);              // Copy constructor
    Book& operator=(const Book& other);   // Copy assignment
    ~Book();                               // Destructor
    
    // Getters
    const std::string& getTitle() const;
    const Author& getAuthor() const;
    int getYear() const;
    int getStock() const;
    
    // Setters
    void setStock(int newStock);
    
    // operator
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
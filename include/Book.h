#pragma once
#include "Item.h"
#include "Author.h"
#include <string>
#include <iostream>

class Book : public Item {
private:
    Author author;
    int stock;
    
public:
    // Constructor (calls Item constructor)
    Book(const std::string& title, const Author& author, int year, int stock);
    
    // Rule of Three (M1'den kalıyor)
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book();
    
    // Virtual functions override
    void display() const override;
    Book* clone() const override;
    std::string getType() const override;
    double calculateLateFee(int days) const override;
    
    // Getters
    const Author& getAuthor() const;
    int getStock() const;
    void setStock(int newStock);
};
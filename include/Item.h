#pragma once
#include <string>
#include <iostream>

class Item {
protected:
    std::string title;
    int year;
    
public:
    // Constructor
    Item(const std::string& title, int year);
    
    // Virtual destructor (ZORUNLU!)
    virtual ~Item() = default;
    
    // Pure virtual functions
    virtual void display() const = 0;
    virtual Item* clone() const = 0;
    virtual std::string getType() const = 0;
    
    // Virtual function with implementation (tema-specific!)
    virtual double calculateLateFee(int days) const = 0;
    
    // Getters
    const std::string& getTitle() const;
    int getYear() const;
    
    // operator<< (non-virtual interface)
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};
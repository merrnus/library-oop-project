#pragma once
#include "Item.h"
#include <string>
#include <iostream>

class DVD : public Item {
private:
    std::string director;
    int duration; // minutes
    
public:
    // Constructor
    DVD(const std::string& title, const std::string& director, 
        int year, int duration);
    
    // Copy constructor
    DVD(const DVD& other);
    
    // Virtual functions override
    void display() const override;
    DVD* clone() const override;
    std::string getType() const override;
    double calculateLateFee(int days) const override;
    
    // Getters
    const std::string& getDirector() const;
    int getDuration() const;
    
    // Destructor
    ~DVD();
};
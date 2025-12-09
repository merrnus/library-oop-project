#pragma once
#include "Item.h"
#include <string>
#include <iostream>

class Magazine : public Item {
private:
    std::string publisher;
    int issueNumber;
    
public:
    // Constructor
    Magazine(const std::string& title, const std::string& publisher, 
             int year, int issueNumber);
    
    // Copy constructor
    Magazine(const Magazine& other);
    
    // Virtual functions override
    void display() const override;
    Magazine* clone() const override;
    std::string getType() const override;
    double calculateLateFee(int days) const override;
    
    // Getters
    const std::string& getPublisher() const;
    int getIssueNumber() const;
    
    // Destructor
    ~Magazine();
};
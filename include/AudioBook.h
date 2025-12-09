#pragma once
#include "Item.h"
#include "Author.h"
#include <string>
#include <iostream>

class AudioBook : public Item {
private:
    Author narrator;
    int durationMinutes;
    std::string format; // MP3, M4B, etc.
    
public:
    // Constructor
    AudioBook(const std::string& title, const Author& narrator, 
              int year, int durationMinutes, const std::string& format);
    
    // Copy constructor
    AudioBook(const AudioBook& other);
    
    // Virtual functions override
    void display() const override;
    AudioBook* clone() const override;
    std::string getType() const override;
    double calculateLateFee(int days) const override;
    
    // Getters
    const Author& getNarrator() const;
    int getDuration() const;
    const std::string& getFormat() const;
    
    // Destructor
    ~AudioBook();
};
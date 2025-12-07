#pragma once
#include <string>
#include <iostream>

class Author {
private:
    std::string name;
    std::string country;

public:
    // Constructor
    Author(const std::string& name, const std::string& country);
    
    // Getters
    const std::string& getName() const;
    const std::string& getCountry() const;
    
    // operator
    friend std::ostream& operator<<(std::ostream& os, const Author& author);
};
#include "Author.h"

// Constructor
Author::Author(const std::string& name, const std::string& country) 
    : name(name), country(country) {}

// Getters
std::string Author::getName() const {
    return name;
}

std::string Author::getCountry() const {
    return country;
}

// operator
std::ostream& operator<<(std::ostream& os, const Author& author) {
    os << author.name << " (" << author.country << ")";
    return os;
}
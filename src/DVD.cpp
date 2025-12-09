#include "../include/DVD.h"

// Constructor
DVD::DVD(const std::string& title, const std::string& director,
         int year, int duration)
    : Item(title, year), director(director), duration(duration) {
    std::cout << "DVD constructor called for: " << title << "\n";
}

// Copy constructor
DVD::DVD(const DVD& other)
    : Item(other.title, other.year), director(other.director), 
      duration(other.duration) {
    std::cout << "DVD copy constructor called for: " << title << "\n";
}

// Destructor
DVD::~DVD() {
    std::cout << "DVD destructor called for: " << title << "\n";
}

// Virtual function implementations
void DVD::display() const {
    std::cout << "DVD: \"" << title << "\", Director: " << director
              << ", Year: " << year << ", Duration: " << duration << " min";
}

DVD* DVD::clone() const {
    return new DVD(*this);
}

std::string DVD::getType() const {
    return "DVD";
}

double DVD::calculateLateFee(int days) const {
    // DVDs: 1.0 lei per day (most expensive)
    return days * 1.0;
}

// Getters
const std::string& DVD::getDirector() const {
    return director;
}

int DVD::getDuration() const {
    return duration;
}
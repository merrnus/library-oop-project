#include "../include/Magazine.h"

// Constructor
Magazine::Magazine(const std::string& title, const std::string& publisher,
                   int year, int issueNumber)
    : Item(title, year), publisher(publisher), issueNumber(issueNumber) {
    std::cout << "Magazine constructor called for: " << title << "\n";
}

// Copy constructor
Magazine::Magazine(const Magazine& other)
    : Item(other.title, other.year), publisher(other.publisher), 
      issueNumber(other.issueNumber) {
    std::cout << "Magazine copy constructor called for: " << title << "\n";
}

// Destructor
Magazine::~Magazine() {
    std::cout << "Magazine destructor called for: " << title << "\n";
}

// Virtual function implementations
void Magazine::display() const {
    std::cout << "Magazine: \"" << title << "\", Publisher: " << publisher
              << ", Year: " << year << ", Issue #" << issueNumber;
}

Magazine* Magazine::clone() const {
    return new Magazine(*this);
}

std::string Magazine::getType() const {
    return "Magazine";
}

double Magazine::calculateLateFee(int days) const {
    // Magazines: 0.3 lei per day (cheaper than books)
    return days * 0.3;
}

// Getters
const std::string& Magazine::getPublisher() const {
    return publisher;
}

int Magazine::getIssueNumber() const {
    return issueNumber;
}
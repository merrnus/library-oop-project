#include "../include/Item.h"

// Constructor
Item::Item(const std::string& title, int year)
    : title(title), year(year) {}

// Getters
const std::string& Item::getTitle() const {
    return title;
}

int Item::getYear() const {
    return year;
}

// operator<< (calls virtual display)
std::ostream& operator<<(std::ostream& os, const Item& item) {
    item.display();  // Virtual call!
    return os;
}
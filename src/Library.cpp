#include "../include/Library.h"
#include <algorithm>
#include "../include/Book.h"
#include "../include/Magazine.h"
#include "../include/DVD.h"
#include "../include/Author.h"
#include "../include/AudioBook.h"
#include <fstream>
#include <sstream>

// Static member initialization
int Library::totalLibraries = 0;

// Constructor
Library::Library(const std::string& name) : name(name) {
    totalLibraries++;
    std::cout << "Library constructor called: " << name << "\n";
}

// Copy constructor (DEEP COPY!)
Library::Library(const Library& other) : name(other.name) {
    totalLibraries++;
    std::cout << "Library copy constructor called: " << name << "\n";
    
    // Deep copy all items using clone()
    for (const auto& item : other.items) {
        items.push_back(std::unique_ptr<Item>(item->clone()));
    }
}

// Copy assignment (copy-and-swap idiom!)
Library& Library::operator=(Library other) {
    std::cout << "Library copy assignment called\n";
    swap(other);
    return *this;
}

// Destructor
Library::~Library() {
    totalLibraries--;
    std::cout << "Library destructor called: " << name << "\n";
    // Smart pointers auto-delete!
}

// Swap helper
void Library::swap(Library& other) noexcept {
    std::swap(name, other.name);
    std::swap(items, other.items);
}

// Add item (throws exception if null)
void Library::addItem(std::unique_ptr<Item> item) {
    if (!item) {
        throw InvalidItemException("Cannot add null item");
    }
    
    // Check for duplicates
    const std::string& title = item->getTitle();
    for (const auto& existingItem : items) {
        if (existingItem->getTitle() == title) {
            throw DuplicateItemException(title);
        }
    }
    
    std::cout << "Added item: " << item->getTitle() << "\n";
    items.push_back(std::move(item));
}

// Remove item (throws exception if not found)
bool Library::removeItem(const std::string& title) {
    auto it = std::find_if(items.begin(), items.end(),
        [&title](const std::unique_ptr<Item>& item) {
            return item->getTitle() == title;
        });
    
    if (it != items.end()) {
        std::cout << "Removed item: " << title << "\n";
        items.erase(it);
        return true;
    }
    
    throw ItemNotFoundException(title);
}

// Find items by type (uses dynamic_cast!)
std::vector<Item*> Library::findItemsByType(const std::string& type) const {
    std::vector<Item*> result;
    
    for (const auto& item : items) {
        if (item->getType() == type) {
            result.push_back(item.get());
        }
    }
    
    return result;
}

// Display all items
void Library::displayAllItems() const {
    std::cout << "\n=== Library: " << name << " ===" << "\n";
    std::cout << "Total items: " << items.size() << "\n\n";
    
    for (const auto& item : items) {
        item->display();
        std::cout << "\n";
    }
}

// Static function
int Library::getTotalLibraries() {
    return totalLibraries;
}

// Getters
const std::string& Library::getName() const {
    return name;
}

int Library::getItemCount() const {
    return items.size();
}

// operator
std::ostream& operator<<(std::ostream& os, const Library& library) {
    os << "Library: " << library.name 
       << " (Items: " << library.items.size() << ")";
    return os;
}

// Load books from file
void Library::loadBooksFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw InvalidItemException("Cannot open file: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // Parse: title|author_name|author_country|year|stock
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        size_t pos4 = line.find('|', pos3 + 1);
        
        if (pos1 == std::string::npos || pos4 == std::string::npos) continue;
        
        std::string title = line.substr(0, pos1);
        std::string authorName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string authorCountry = line.substr(pos2 + 1, pos3 - pos2 - 1);
        int year = std::stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
        int stock = std::stoi(line.substr(pos4 + 1));
        
        Author author(authorName, authorCountry);
        addItem(std::make_unique<Book>(title, author, year, stock));
    }
    
    file.close();
    std::cout << "Loaded books from: " << filename << "\n";
}

// Load magazines from file
void Library::loadMagazinesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw InvalidItemException("Cannot open file: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // Parse: title|publisher|year|issue_number
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        
        if (pos1 == std::string::npos || pos3 == std::string::npos) continue;
        
        std::string title = line.substr(0, pos1);
        std::string publisher = line.substr(pos1 + 1, pos2 - pos1 - 1);
        int year = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        int issueNumber = std::stoi(line.substr(pos3 + 1));
        
        addItem(std::make_unique<Magazine>(title, publisher, year, issueNumber));
    }
    
    file.close();
    std::cout << "Loaded magazines from: " << filename << "\n";
}

// Load DVDs from file
void Library::loadDVDsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw InvalidItemException("Cannot open file: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // Parse: title|director|year|duration
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        
        if (pos1 == std::string::npos || pos3 == std::string::npos) continue;
        
        std::string title = line.substr(0, pos1);
        std::string director = line.substr(pos1 + 1, pos2 - pos1 - 1);
        int year = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        int duration = std::stoi(line.substr(pos3 + 1));
        
        addItem(std::make_unique<DVD>(title, director, year, duration));
    }
    
    file.close();
    std::cout << "Loaded DVDs from: " << filename << "\n";
}

// dynamic_cast usage - downcast from Item* to Book*
void Library::displayBooksWithAuthors() const {
    std::cout << "\n=== Books with Author Information (dynamic_cast) ===\n";
    
    int bookCount = 0;
    for (const auto& item : items) {
        // Try to downcast Item* to Book*
        if (Book* book = dynamic_cast<Book*>(item.get())) {
            // Successfully casted to Book!
            std::cout << "Book: \"" << book->getTitle() << "\" by " 
                      << book->getAuthor() << ", Stock: " << book->getStock() << "\n";
            bookCount++;
        }
    }
    
    std::cout << "Total books found: " << bookCount << "\n";
}

// Load audiobooks from file
void Library::loadAudioBooksFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw InvalidItemException("Cannot open file: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // Parse: title|narrator_name|narrator_country|year|duration|format
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        size_t pos4 = line.find('|', pos3 + 1);
        size_t pos5 = line.find('|', pos4 + 1);
        
        if (pos1 == std::string::npos || pos5 == std::string::npos) continue;
        
        std::string title = line.substr(0, pos1);
        std::string narratorName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string narratorCountry = line.substr(pos2 + 1, pos3 - pos2 - 1);
        int year = std::stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
        int duration = std::stoi(line.substr(pos4 + 1, pos5 - pos4 - 1));
        std::string format = line.substr(pos5 + 1);
        
        Author narrator(narratorName, narratorCountry);
        addItem(std::make_unique<AudioBook>(title, narrator, year, duration, format));
    }
    
    file.close();
    std::cout << "Loaded audiobooks from: " << filename << "\n";
}
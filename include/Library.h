#pragma once
#include "Item.h"
#include "LibraryExceptions.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Library {
private:
    std::string name;
    std::vector<std::unique_ptr<Item>> items;  // Smart pointers!
    static int totalLibraries;  // Static member!
    
public:
    // Constructor
    explicit Library(const std::string& name);
    
    // Copy constructor (deep copy!)
    Library(const Library& other);
    
    // Copy assignment (copy-and-swap idiom!)
    Library& operator=(Library other);
    
    // Destructor
    ~Library();
    
    // Main functions
    void addItem(std::unique_ptr<Item> item);
    bool removeItem(const std::string& title);
    std::vector<Item*> findItemsByType(const std::string& type) const;
    void displayAllItems() const;

    // dynamic_cast usage - get all books with author info
    void displayBooksWithAuthors() const;

    // File loading functions
    void loadBooksFromFile(const std::string& filename);
    void loadMagazinesFromFile(const std::string& filename);
    void loadDVDsFromFile(const std::string& filename);
    void loadAudioBooksFromFile(const std::string& filename);
    
    // Static function
    static int getTotalLibraries();
    
    // Getters
    const std::string& getName() const;
    int getItemCount() const;
    
    // operator
    friend std::ostream& operator<<(std::ostream& os, const Library& library);
    
private:
    // Helper for swap
    void swap(Library& other) noexcept;
};
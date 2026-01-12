#include "../include/LibraryManager.h"
#include "../include/Library.h"
#include <iostream>
#include <algorithm>

// Private constructor
LibraryManager::LibraryManager() {
    std::cout << "LibraryManager singleton instance created\n";
}

// Destructor
LibraryManager::~LibraryManager() {
    std::cout << "LibraryManager singleton instance destroyed\n";
}

// Singleton getInstance
LibraryManager& LibraryManager::getInstance() {
    static LibraryManager instance;
    return instance;
}

// Register library
void LibraryManager::registerLibrary(Library* lib) {
    if (lib) {
        libraries.push_back(lib);
        std::cout << "Library registered with LibraryManager\n";
    }
}

// Unregister library
void LibraryManager::unregisterLibrary(Library* lib) {
    auto it = std::find(libraries.begin(), libraries.end(), lib);
    if (it != libraries.end()) {
        libraries.erase(it);
        std::cout << "Library unregistered from LibraryManager\n";
    }
}

// Get library count
size_t LibraryManager::getLibraryCount() const {
    return libraries.size();
}
#pragma once
#include <memory>
#include <vector>
#include <string>

class Library;

class LibraryManager {
private:
    // Private constructor (Singleton pattern)
    LibraryManager();
    
    std::vector<Library*> libraries;
    
public:
    // Delete copy constructor and assignment operator
    LibraryManager(const LibraryManager&) = delete;
    LibraryManager& operator=(const LibraryManager&) = delete;
    
    // Singleton instance getter
    static LibraryManager& getInstance();
    
    // Library management
    void registerLibrary(Library* lib);
    void unregisterLibrary(Library* lib);
    size_t getLibraryCount() const;
    
    // Destructor
    ~LibraryManager();
};
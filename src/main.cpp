#include "../include/Library.h"
#include "../include/Book.h"
#include "../include/Magazine.h"
#include "../include/DVD.h"
#include "../include/AudioBook.h"
#include "../include/Author.h"
#include "../include/ItemCollection.h"
#include "../include/ItemHelpers.h"
#include "../include/LibraryManager.h"
#include <iostream>
#include <memory>


int main() {
    std::cout << "=== Library Management System M2 ===\n\n";
    
    try {
        // Create library
        Library library("Central Library");
        std::cout << "Total libraries: " << Library::getTotalLibraries() << "\n\n";
        
        std::cout << "=== Loading Items from Files ===\n";
        
        // Load from files (NO HARDCODED DATA!)
        library.loadBooksFromFile("data/books.txt");
        library.loadMagazinesFromFile("data/magazines.txt");
        library.loadDVDsFromFile("data/dvds.txt");
        library.loadAudioBooksFromFile("data/audiobooks.txt");
        
        std::cout << "\n";
        
        // Display all items
        library.displayAllItems();

        // Test dynamic_cast
        library.displayBooksWithAuthors();
        
        std::cout << "\n=== Testing Polymorphism ===\n";
        // Find items by type
        auto books = library.findItemsByType("Book");
        auto magazines = library.findItemsByType("Magazine");
        auto dvds = library.findItemsByType("DVD");
        auto audiobooks = library.findItemsByType("AudioBook");

        std::cout << "Books: " << books.size() << "\n";
        std::cout << "Magazines: " << magazines.size() << "\n";
        std::cout << "DVDs: " << dvds.size() << "\n";
        std::cout << "AudioBooks: " << audiobooks.size() << "\n";

        
        // Calculate late fees (virtual function - tema specific!)
        std::cout << "\n=== Late Fee Calculations (Virtual Function) ===\n";
        if (!books.empty()) {
            std::cout << "Book '" << books[0]->getTitle() << "': " 
                      << books[0]->calculateLateFee(10) << " lei (10 days)\n";
        }
        if (!magazines.empty()) {
            std::cout << "Magazine '" << magazines[0]->getTitle() << "': " 
                      << magazines[0]->calculateLateFee(10) << " lei (10 days)\n";
        }
        if (!dvds.empty()) {
            std::cout << "DVD '" << dvds[0]->getTitle() << "': " 
                      << dvds[0]->calculateLateFee(10) << " lei (10 days)\n";
        }
        if (!audiobooks.empty()) {
            std::cout << "AudioBook '" << audiobooks[0]->getTitle() << "': " 
                      << audiobooks[0]->calculateLateFee(10) << " lei (10 days)\n";
        }
        
        std::cout << "\n=== Testing Copy Constructor (Deep Copy) ===\n";
        Library library2 = library;
        std::cout << "Original: " << library << "\n";
        std::cout << "Copy: " << library2 << "\n";
        
        std::cout << "\n=== Testing Exception: Remove Item ===\n";
        library.removeItem("1984");
        std::cout << "After removal: " << library << "\n";
        
        std::cout << "\n=== Testing Exception: Item Not Found ===\n";
        try {
            library.removeItem("Non-existent Book");
        } catch (const ItemNotFoundException& e) {
            std::cout << "✓ Caught exception: " << e.what() << "\n";
        }
        
        std::cout << "\n=== Testing Exception: Null Item ===\n";
        try {
            library.addItem(nullptr);
        } catch (const InvalidItemException& e) {
            std::cout << "✓ Caught exception: " << e.what() << "\n";
        }
        
        std::cout << "\n=== Testing Exception: Duplicate Item ===\n";
        try {
            Author author("Test", "Test");
            library.addItem(std::make_unique<Book>("Animal Farm", author, 1945, 3));
        } catch (const DuplicateItemException& e) {
            std::cout << "✓ Caught exception: " << e.what() << "\n";
        }
        
        std::cout << "\n=== Testing Static Member ===\n";
        std::cout << "Total libraries: " << Library::getTotalLibraries() << "\n";
        
        {
            Library tempLib("Temporary Library");
            std::cout << "After creating temp library: " << Library::getTotalLibraries() << "\n";
        }
        std::cout << "After temp library destroyed: " << Library::getTotalLibraries() << "\n";

        std::cout << "\n=== M3: TEMPLATE CLASS TEST (ItemCollection) ===\n";
        ItemCollection<Book> bookCollection;
        bookCollection.add(std::make_unique<Book>("Test Book 1", Author("Author1", "Country1"), 2020, 5));
        bookCollection.add(std::make_unique<Book>("Test Book 2", Author("Author2", "Country2"), 2021, 3));
        std::cout << "Book collection size: " << bookCollection.size() << "\n";
        
        ItemCollection<Magazine> magazineCollection;
        magazineCollection.add(std::make_unique<Magazine>("Test Mag 1", "Pub1", 2022, 10));
        std::cout << "Magazine collection size: " << magazineCollection.size() << "\n";
        
        std::cout << "\n=== M3: TEMPLATE FUNCTION TEST ===\n";
        auto allBooks = library.findItemsByType("Book");
        if (!allBooks.empty()) {
            std::cout << "Sorting books...\n";
            sortItemsByTitle(allBooks);
            std::cout << "First book after sort: " << allBooks[0]->getTitle() << "\n";
        }
        
        auto recentBooks = filterItemsByYear(allBooks, 1980, 2000);
        std::cout << "Books from 1980-2000: " << recentBooks.size() << "\n";
        
        std::cout << "\n=== M3: SINGLETON TEST ===\n";
        std::cout << "LibraryManager total: " << LibraryManager::getInstance().getLibraryCount() << "\n";
        
        std::cout << "\n=== M3: FACTORY PATTERN ===\n";
        std::cout << "Factory used in loadFromFile functions!\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }
    
    std::cout << "\n=== Program End ===\n";

    return 0;
}
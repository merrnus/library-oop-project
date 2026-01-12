#pragma once
#include <memory>
#include <string>
#include "Item.h"

class ItemFactory {
public:
    // Factory method: Create item from file line
    static std::unique_ptr<Item> createFromLine(const std::string& type, const std::string& line);
    
private:
    // Helper parsers
    static std::unique_ptr<Item> parseBook(const std::string& line);
    static std::unique_ptr<Item> parseMagazine(const std::string& line);
    static std::unique_ptr<Item> parseDVD(const std::string& line);
    static std::unique_ptr<Item> parseAudioBook(const std::string& line);
};
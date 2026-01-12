#include "../include/ItemFactory.h"
#include "../include/Book.h"
#include "../include/Magazine.h"
#include "../include/DVD.h"
#include "../include/AudioBook.h"
#include "../include/Author.h"
#include <sstream>

std::unique_ptr<Item> ItemFactory::createFromLine(const std::string& type, const std::string& line) {
    if (type == "book") {
        return parseBook(line);
    } else if (type == "magazine") {
        return parseMagazine(line);
    } else if (type == "dvd") {
        return parseDVD(line);
    } else if (type == "audiobook") {
        return parseAudioBook(line);
    }
    return nullptr;
}

std::unique_ptr<Item> ItemFactory::parseBook(const std::string& line) {
    // Parse: title|author_name|author_country|year|stock
    size_t pos1 = line.find('|');
    size_t pos2 = line.find('|', pos1 + 1);
    size_t pos3 = line.find('|', pos2 + 1);
    size_t pos4 = line.find('|', pos3 + 1);
    
    if (pos1 == std::string::npos || pos4 == std::string::npos) {
        return nullptr;
    }
    
    std::string title = line.substr(0, pos1);
    std::string authorName = line.substr(pos1 + 1, pos2 - pos1 - 1);
    std::string authorCountry = line.substr(pos2 + 1, pos3 - pos2 - 1);
    int year = std::stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
    int stock = std::stoi(line.substr(pos4 + 1));
    
    Author author(authorName, authorCountry);
    return std::make_unique<Book>(title, author, year, stock);
}

std::unique_ptr<Item> ItemFactory::parseMagazine(const std::string& line) {
    // Parse: title|publisher|year|issue_number
    size_t pos1 = line.find('|');
    size_t pos2 = line.find('|', pos1 + 1);
    size_t pos3 = line.find('|', pos2 + 1);
    
    if (pos1 == std::string::npos || pos3 == std::string::npos) {
        return nullptr;
    }
    
    std::string title = line.substr(0, pos1);
    std::string publisher = line.substr(pos1 + 1, pos2 - pos1 - 1);
    int year = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
    int issueNumber = std::stoi(line.substr(pos3 + 1));
    
    return std::make_unique<Magazine>(title, publisher, year, issueNumber);
}

std::unique_ptr<Item> ItemFactory::parseDVD(const std::string& line) {
    // Parse: title|director|year|duration
    size_t pos1 = line.find('|');
    size_t pos2 = line.find('|', pos1 + 1);
    size_t pos3 = line.find('|', pos2 + 1);
    
    if (pos1 == std::string::npos || pos3 == std::string::npos) {
        return nullptr;
    }
    
    std::string title = line.substr(0, pos1);
    std::string director = line.substr(pos1 + 1, pos2 - pos1 - 1);
    int year = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
    int duration = std::stoi(line.substr(pos3 + 1));
    
    return std::make_unique<DVD>(title, director, year, duration);
}

std::unique_ptr<Item> ItemFactory::parseAudioBook(const std::string& line) {
    // Parse: title|narrator_name|narrator_country|year|duration|format
    size_t pos1 = line.find('|');
    size_t pos2 = line.find('|', pos1 + 1);
    size_t pos3 = line.find('|', pos2 + 1);
    size_t pos4 = line.find('|', pos3 + 1);
    size_t pos5 = line.find('|', pos4 + 1);
    
    if (pos1 == std::string::npos || pos5 == std::string::npos) {
        return nullptr;
    }
    
    std::string title = line.substr(0, pos1);
    std::string narratorName = line.substr(pos1 + 1, pos2 - pos1 - 1);
    std::string narratorCountry = line.substr(pos2 + 1, pos3 - pos2 - 1);
    int year = std::stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
    int duration = std::stoi(line.substr(pos4 + 1, pos5 - pos4 - 1));
    std::string format = line.substr(pos5 + 1);
    
    Author narrator(narratorName, narratorCountry);
    return std::make_unique<AudioBook>(title, narrator, year, duration, format);
}
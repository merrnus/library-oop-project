#pragma once
#include <exception>
#include <string>

// Base exception class
class LibraryException : public std::exception {
protected:
    std::string message;
    
public:
    explicit LibraryException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// 1. Item not found in library
class ItemNotFoundException : public LibraryException {
public:
    explicit ItemNotFoundException(const std::string& title)
        : LibraryException("Item not found: " + title) {}
};

// 2. Trying to add duplicate item
class DuplicateItemException : public LibraryException {
public:
    explicit DuplicateItemException(const std::string& title)
        : LibraryException("Duplicate item: " + title) {}
};

// 3. Invalid item (null pointer, invalid data)
class InvalidItemException : public LibraryException {
public:
    explicit InvalidItemException(const std::string& reason)
        : LibraryException("Invalid item: " + reason) {}
};
#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "Item.h"

// Template function 1: Sort items by title
template <typename T>
void sortItemsByTitle(std::vector<T*>& items) {
    std::sort(items.begin(), items.end(), 
              [](T* a, T* b) { 
                  return a->getTitle() < b->getTitle(); 
              });
}

// Template function 2: Filter items by year
template <typename T>
std::vector<T*> filterItemsByYear(const std::vector<T*>& items, int minYear, int maxYear) {
    std::vector<T*> result;
    std::copy_if(items.begin(), items.end(), 
                 std::back_inserter(result),
                 [minYear, maxYear](T* item) {
                     int year = item->getYear();
                     return year >= minYear && year <= maxYear;
                 });
    return result;
}

// Template function 3: Count items by type
template <typename T>
size_t countItemsByType(const std::vector<std::unique_ptr<T>>& items, const std::string& type) {
    return std::count_if(items.begin(), items.end(),
                        [&type](const std::unique_ptr<T>& item) {
                            return item->getType() == type;
                        });
}
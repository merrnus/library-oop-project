#pragma once
#include <vector>
#include <algorithm>
#include <memory>

template <typename T>
class ItemCollection {
private:
    std::vector<std::unique_ptr<T>> items;
    
public:
    ItemCollection() = default;
    
    // Add item
    void add(std::unique_ptr<T> item) {
        items.push_back(std::move(item));
    }
    
    // Get all items
    const std::vector<std::unique_ptr<T>>& getAll() const {
        return items;
    }
    
    // Get size
    size_t size() const {
        return items.size();
    }
    
    // Clear all
    void clear() {
        items.clear();
    }
    
    // Find by predicate
    template <typename Predicate>
    std::vector<T*> findIf(Predicate pred) const {
        std::vector<T*> result;
        for (const auto& item : items) {
            if (pred(item.get())) {
                result.push_back(item.get());
            }
        }
        return result;
    }
};
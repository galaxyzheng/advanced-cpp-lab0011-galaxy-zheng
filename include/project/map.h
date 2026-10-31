#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

struct KeyValuePair {
    std::string key;
    int value;
};

class Map {
public:
    Map();

    bool empty() const noexcept;
    std::size_t size() const noexcept;
    bool contains(const std::string& key) const;
    bool insert(const std::string& key, int value);
    bool update(const std::string& key, int newValue);
    bool erase(const std::string& key);
    int at(const std::string& key) const;
    int& at(const std::string& key);
    std::vector<std::string> keys() const;
    std::vector<int> values() const;
    bool isSorted() const noexcept;

private:
    std::vector<KeyValuePair> entries_;

    std::size_t findIndex(const std::string& key) const;
    void sortEntries();
};

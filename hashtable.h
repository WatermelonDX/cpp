#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <optional>

class HashTable {
public:
    HashTable();

    // Insert or update a key-value pair.
    void setKey(const std::string& key, int value);

    // Get value by key. Returns nullopt if key is not found.
    std::optional<int> getKey(const std::string& key) const;

    // Remove all key-value pairs from the hash table.
    void clear();
};

#endif // HASHTABLE_H

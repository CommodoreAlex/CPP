#ifndef OBJECT_STORE_HPP
#define OBJECT_STORE_HPP

#include <string>

// Adds a file to the object store, returns the object hash (hex string)
// Returns empty string on failure.
std::string addBlob(const std::string& filePath);

#endif // OBJECT_STORE_HPP


#pragma once
#include <string>

// Adds a file to the object store, returns the object hash (hex string)
// Returns empty string on failure.
std::string addBlob(const std::string& filePath);

std::string getBlobPath(const std::string& hash);  // just declaration

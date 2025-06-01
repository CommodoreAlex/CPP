#pragma once
#include <string>
#include <unordered_map>

// Declare addFileToIndex
void addFileToIndex(const std::string& filename, const std::string& hash);

// Declare readIndex
std::unordered_map<std::string, std::string> readIndex();

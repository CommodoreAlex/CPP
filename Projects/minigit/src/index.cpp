#include "index.hpp"
#include <fstream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> readIndex() {
    std::unordered_map<std::string, std::string> index;
    std::ifstream file(".minigit/index");
    std::string filename, hash;

    while (file >> filename >> hash) {
        index[filename] = hash;
    }
    return index;
}

void writeIndex(const std::unordered_map<std::string, std::string>& index) {
    std::ofstream file(".minigit/index", std::ios::trunc);
    for (const auto& [filename, hash] : index) {
        file << filename << " " << hash << "\n";
    }
}

void addFileToIndex(const std::string& filename, const std::string& hash) {
    auto index = readIndex();
    index[filename] = hash;
    writeIndex(index);
}

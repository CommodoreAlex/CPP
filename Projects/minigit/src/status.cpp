#include "status.hpp"
#include "index.hpp"        // Include the header that declares readIndex()
#include "object_store.hpp"
#include "sha1.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace fs = std::filesystem;

// Remove the readIndex() definition here! Just use the one from index.cpp

std::string fileToSha1(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return sha1(buffer.str());
}

void showStatus() {
    auto index = readIndex();  // Use readIndex() from index.cpp
    std::unordered_set<std::string> seen;

    std::cout << "== Staged Files ==\n";
    for (const auto& [filename, hash] : index) {
        seen.insert(filename);
        if (!fs::exists(filename)) {
            std::cout << "  deleted: " << filename << "\n";
            continue;
        }

        std::string currentHash = fileToSha1(filename);
        if (currentHash == hash)
            std::cout << "    staged: " << filename << "\n";
        else
            std::cout << "    modified: " << filename << "\n";
    }

    std::cout << "\n== Untracked Files ==\n";
    for (const auto& entry : fs::directory_iterator(".")) {
        std::string path = entry.path().filename().string();
        if (path == ".minigit" || seen.count(path) || entry.is_directory())
            continue;
        std::cout << "    untracked: " << path << "\n";
    }
}

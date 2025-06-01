#include "commit.hpp"
#include "sha1.hpp"
#include "log.hpp"
#include "index.hpp"
#include "object_store.hpp"
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <iostream>
#include <algorithm>

namespace fs = std::filesystem;

std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%F %T");
    return ss.str();
}

// Removed getBlobPath function here to avoid redefinition

std::string getCurrentCommitId() {
    std::ifstream head(".minigit/HEAD");
    std::string id;
    if (head && std::getline(head, id)) {
        // Basic SHA-1 validation: 40 hex characters
        if (id.size() == 40 && std::all_of(id.begin(), id.end(), ::isxdigit)) {
            return id;
        }
    }
    return "";
}

void updateHead(const std::string& id) {
    std::ofstream head(".minigit/HEAD", std::ios::trunc);
    head << id;
}

std::string commitToString(const Commit& commit) {
    std::stringstream ss;
    ss << "id: " << commit.id << "\n";
    ss << "message: " << commit.message << "\n";
    ss << "timestamp: " << commit.timestamp << "\n";
    ss << "parent: " << commit.parent << "\n";
    for (const auto& [file, hash] : commit.files) {
        ss << "file: " << file << " " << hash << "\n";
    }
    return ss.str();
}

std::string createCommit(const std::string& message) {
    auto index = readIndex();
    if (index.empty()) {
        std::cerr << "Nothing to commit. Index is empty.\n";
        return "";
    }

    // Verify blobs exist
    for (const auto& [file, hash] : index) {
        std::string path = getBlobPath(hash);
        if (!fs::exists(path)) {
            std::cerr << "Missing blob for file '" << file << "' with hash " << hash << "\n";
            return "";
        }
    }

    Commit commit;
    commit.message = message;
    commit.timestamp = getCurrentTimestamp();

    std::ifstream head(".minigit/HEAD");
    std::string parent;
    if (head && std::getline(head, parent) && !parent.empty()) {
        commit.parent = parent;
    } else {
        commit.parent = "";
    }

    commit.files = index;

    std::stringstream ss;
    ss << "id: " << sha1(commit.message + commit.timestamp) << "\n";
    ss << "message: " << commit.message << "\n";
    ss << "timestamp: " << commit.timestamp << "\n";
    ss << "parent: " << commit.parent << "\n";
    for (const auto& [file, hash] : commit.files) {
        ss << "file: " << file << " " << hash << "\n";
    }

    std::string data = ss.str();
    std::string id = sha1(data);
    commit.id = id;

    fs::create_directories(".minigit/commits");
    std::ofstream out(".minigit/commits/" + id);
    out << commitToString(commit);

    updateHead(id);
    std::cout << "Committed as " << id << "\n";
    return id;
}

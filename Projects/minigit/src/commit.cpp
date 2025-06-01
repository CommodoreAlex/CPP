#include "commit.hpp"
#include "sha1.hpp"
#include "index.hpp"
#include "object_store.hpp"
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::string getCurrentTimestamp() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::stringstream ss;;
	ss << std::put_time(std::localtime(&now_c), "%F %T");
	return ss.str();
}

std::string getCurrentCommitId() {
	std::ifstream head(".minigit/HEAD");
	std::string id;
	std::getline(head, id);
	return id;
}

void updateHead(const std::string& id) {
	std::ofstream head(".minigit/HEAD", std::ios::trunc);
	head << id;
}

// Structured binding, to unpack key-value pairs directly from std::unordered_map
std::string commitToString(const Commit& commit) {
	std::stringstream ss;
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

    // Prepare commit structure
    Commit commit;
    commit.message = message;
    commit.timestamp = getCurrentTimestamp();

    // Only add parent if HEAD contains a valid SHA
    std::ifstream head(".minigit/HEAD");
    std::string parent;
    if (head && std::getline(head, parent) && !parent.empty()) {
        commit.parent = parent;
    } else {
        commit.parent = ""; // No parent (first commit)
    }

    commit.files = index;

    // Serialize commit
    std::stringstream ss;
    ss << "id: " << sha1(commit.message + commit.timestamp) << "\n"; // Temporarily use message + timestamp to derive ID
    ss << "message: " << commit.message << "\n";
    ss << "timestamp: " << commit.timestamp << "\n";
    ss << "parent: " << commit.parent << "\n";

    for (const auto& [file, hash] : commit.files) {
        ss << "file: " << file << " " << hash << "\n";
    }

    std::string data = ss.str();
    std::string id = sha1(data); // Final commit ID should be SHA of full content
    commit.id = id;

    // Write final commit file with correct id
    std::ofstream out(".minigit/objects/" + id);
    out << "id: " << id << "\n";
    out << "message: " << commit.message << "\n";
    out << "timestamp: " << commit.timestamp << "\n";
    out << "parent: " << commit.parent << "\n";
    for (const auto& [file, hash] : commit.files) {
        out << "file: " << file << " " << hash << "\n";
    }

    updateHead(id);
    std::cout << "Committed as " << id << "\n";
    return id;
}


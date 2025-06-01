#include "checkout.hpp"
#include "commit.hpp"
#include "object_store.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

bool checkoutCommit(const std::string& commitId) {
    Commit commit = loadCommit(commitId);

    if (commit.id.empty()) {
        std::cerr << "Invalid commit ID or failed to load commit.\n";
        return false;
    }

    std::cout << "Checking out commit: " << commitId << "\n";

	for (const auto& [filename, blobHash] : commit.files) {
	    std::string blobPath = ".minigit/objects/" + blobHash.substr(0, 2) + "/" + blobHash.substr(2);
	    std::ifstream in(blobPath, std::ios::binary);

	    if (!in) {
	        std::cerr << "Missing blob: " << blobHash << " for file " << filename << "\n";
	        continue;
	    }

	    std::ofstream out(filename, std::ios::binary);
	    out << in.rdbuf();
	    std::cout << "Restored: " << filename << "\n";
	}

    // Update HEAD
    std::ofstream head(".minigit/HEAD", std::ios::trunc);
    head << commitId;

    return true;
}
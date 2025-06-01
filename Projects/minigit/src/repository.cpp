#include "repository.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

bool initRepository() {
    try {
        if (fs::exists(".minigit")) {
            std::cerr << "Repository already initialized.\n";
            return false;
        }

        fs::create_directory(".minigit");
        fs::create_directory(".minigit/objects");
        fs::create_directories(".minigit/refs/heads");

        std::ofstream headFile(".minigit/HEAD");
        if (!headFile) {
            std::cerr << "Failed to create HEAD file.\n";
            return false;
        }
        headFile << "ref: refs/heads/main\n";
        headFile.close();

        std::ofstream mainBranch(".minigit/refs/heads/main");
        if (!mainBranch) {
            std::cerr << "Failed to create main branch file.\n";
            return false;
        }
        mainBranch.close();

        std::cout << "Initialized empty MiniGit repository in " << fs::absolute(".minigit") << "\n";
        return true;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << "\n";
        return false;
    }
}


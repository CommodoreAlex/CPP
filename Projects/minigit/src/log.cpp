#include "log.hpp"
#include "commit.hpp" // For commit struct
#include <fstream>
#include <iostream>
#include <sstream>

// Load commit data from the object file into Commit struct
Commit loadCommit(const std::string& commitId) {
    Commit commit;
    std::ifstream in(".minigit/commits/" + commitId);

    if (!in) {
        std::cerr << "Failed to open commit object: " << commitId << "\n";
        return commit;
    }

    std::string line;
    while (std::getline(in, line)) {
        if (line.find("id: ") == 0) {
            commit.id = line.substr(4);
        } else if (line.find("message: ") == 0) {
            commit.message = line.substr(9);
        } else if (line.find("timestamp: ") == 0) {
            commit.timestamp = line.substr(11);
        } else if (line.find("parent: ") == 0) {
            commit.parent = line.substr(8);
        } else if (line.find("file: ") == 0) {
            // line format: file: <filename> <hash>
            std::istringstream iss(line.substr(6));
            std::string filename, hash;
            iss >> filename >> hash;
            commit.files[filename] = hash;
        }
    }
    return commit;
}


void printLog(const std::string& commitId) {
    if (commitId.empty()) return;

    Commit commit = loadCommit(commitId);
    if (commit.id.empty()) return;

    std::cout << "Commit: " << commit.id << "\n";
    std::cout << "Date: " << commit.timestamp << "\n";
    std::cout << commit.message << "\n\n";

    if (!commit.parent.empty()) {
        printLog(commit.parent);
    }
}

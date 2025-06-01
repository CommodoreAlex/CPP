#pragma once
#include <string>

// Prints the commit history startng from the given commit ID
void printLog(const std::string& commitId);

// Loads a commit object given its commit ID
struct Commit;
Commit loadCommit(const std::string& commitId);
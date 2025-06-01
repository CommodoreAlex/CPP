#pragma once
#include <string>

// Checks out a specific commit ID and restores the working directory state
bool checkoutCommit(const std::string& commitId);

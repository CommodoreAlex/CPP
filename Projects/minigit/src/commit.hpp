#pragma once
#include <string>
#include <unordered_map>

struct Commit {

	std::string id;
	std::string message;
	std::string timestamp;
	std::string parent;
	std::unordered_map<std::string, std::string> files;
};

std::string createCommit(const std::string& message);
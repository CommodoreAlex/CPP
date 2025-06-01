#include "head_utils.hpp"
#include <fstream>
#include <string>

std::string resolveHEAD() {
	std::ifstream headFile(".minigit/HEAD");
	if (!headFile) return"";

	std::string line;
	std::getline(headFile, line);

	if (line.substr(0, 5) == "ref: ") {
		std::string refPath = ".minigit/" + line.substr(5);
		std::ifstream refFile(refPath);
		if (!refFile) return "";
		std::getline(refFile, line);
	}

	return line;
}
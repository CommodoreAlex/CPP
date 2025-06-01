#include "object_store.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
using namespace std;

// Include your SHA-1 implementation here or in a separate file
#include "sha1.hpp"

namespace fs = std::filesystem;

string addBlob(const string& filePath) {

	// Read file content
	ifstream file(filePath, std::ios::binary);
	if (!file) {
		cerr << "Failed to open file: " << filePath << "\n";
		return "";
	}

	ostringstream oss;
	oss << file.rdbuf();
	string content = oss.str();

	// Compute SHA-1 hash of content
	string hash = sha1(content); // sha1() returns hex string
	
	// Prepare object directory and file path
	string dir = ".minigit/objects/" + hash.substr(0, 2);
	string filename = hash.substr(2);

	try {
		if (!fs::exists(dir)) {
			fs::create_directory(dir);
		}
	} catch (const fs::filesystem_error& e) {
		cerr << "Filesystem error: " << e.what() << "\n";
		return "";
	}

	// Write content to object file
	string objectPath = dir + "/" + filename;
	ofstream objFile(objectPath, ios::binary);
	if(!objFile) {
		cerr << "Failed to create object file: " << objectPath << "\n";
		return "";
	}

	objFile.write(content.data(), content.size());
	objFile.close();

	return hash;


}


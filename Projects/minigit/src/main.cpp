#include "repository.hpp"
#include "object_store.hpp"
#include "terminal_utils.hpp"
#include "status.hpp"
#include "index.hpp"
#include <iostream>
using namespace std;

// ANSI Escape Codes for Color
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

bool COLOR_ENABLED = false;

void printHelp(bool color = true) {
    string reset   = color ? RESET : "";
    string red     = color ? RED : "";
    string green   = color ? GREEN : "";
    string yellow  = color ? YELLOW : "";
    string cyan    = color ? CYAN : "";
    string boldwhite = color ? BOLDWHITE : "";

    cout << boldwhite << "MiniGit - A Simplified Version Control System\n" << reset;
    cout << cyan << "Usage:\n" << reset;
    cout << "  " << green << "minigit init" << reset << "                  Initialize a new repository\n";
    cout << "  " << green << "minigit add <filename>" << reset << "        Add a file to staging\n";
    cout << "  " << green << "minigit commit <message>" << reset << "      Commit staged changes\n";
    cout << "  " << green << "minigit log" << reset << "                   Show commit history\n";
    cout << "  " << green << "minigit checkout <id>" << reset << "         Checkout a previous commit\n";
    cout << "  " << green << "minigit status" << reset << "                Show file status\n";
    cout << "  " << green << "minigit help" << reset << "                  Display help\n\n";
}

int main(int argc, char* argv[]) {
    enableColorSupportIfNeeded();
    COLOR_ENABLED = isColorSupported();

    if (argc < 2) {
        cerr << "Error: No command provided.\n";
        printHelp(COLOR_ENABLED);
        return 1;
    }

    std::string command = argv[1];

    if (command == "help") {
        printHelp(COLOR_ENABLED);
    } else if (command == "init") {
        if (!initRepository()) return 1;
    } else if (command == "status") {
        showStatus();
    } else if (command == "add") {
        if (argc != 3) {
            cerr << "Usage: minigit add <file>\n";
            return 1;
        }

        std::string hash = addBlob(argv[2]);

        if (!hash.empty()) {
            addFileToIndex(argv[2], hash);  // Update the index with new file and hash
            cout << "Blob stored with hash: " << hash << "\n";
        } else {
            return 1;
        }
    } else {
        cerr << "Unknown command: " << command << "\n";
        printHelp(COLOR_ENABLED);
        return 1;
    }

    return 0;
}

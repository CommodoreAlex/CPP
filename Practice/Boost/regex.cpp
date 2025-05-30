#include <boost/regex.hpp>
#include <iostream>
#include <string>

// Useful for malware detection, logs parsing, better than std::regex
int main() {
    std::string text = "Malware detected: TrojanX";
    boost::regex pattern("TrojanX");
    
    if (boost::regex_search(text, pattern)) {
        std::cout << "Match found!" << std::endl;
    }
    return 0;
}

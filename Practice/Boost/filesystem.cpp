#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;

int main() {

	boost::filesystem::path path("/home/kali/");
	cout << "Path exists: " << boost::filesystem::exists(path) << endl;
	return 0;
}

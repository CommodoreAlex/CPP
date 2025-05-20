#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

// OS-specific clear command
#ifdef _WIN32
	#define CLEAR_COMMAND "cls"
#else
	#define CLEAR_COMMAND "clear"
#endif

int main(){
	
	while (true) {
		
		// Clear the screen for reporting time
		std::system(CLEAR_COMMAND);

		// Get current system time in raw format via chrono
		auto now = std::chrono::system_clock::now();
		std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

		// Output formatted time
		std::cout << "Digital Clock\n";
		std::cout << "=============\n";
		std::cout << std::ctime(&currentTime); // Converting to human-readable time

		// Waiting one second before refreshing the digital clock
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}

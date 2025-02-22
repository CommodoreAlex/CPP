# Technical Portfolio - C++ Projects

Welcome to my technical portfolio! This repository showcases C++ scripts focused on cybersecurity and system administration tasks.

## Projects Overview

### Security Tools

- **ReverseShell.cpp**: This script creates a reverse shell in C++ that connects to a specified attacker IP and port. Once the connection is established, it redirects the standard input, output, and error to the socket, essentially giving the attacker control over the target machine via a shell (`/bin/sh`). The attacker’s IP and port are defined in the script, and when compiled and executed, the target machine connects back to the attacker, allowing remote command execution. This script is typically used for penetration testing or as an educational demonstration of reverse shell functionality.

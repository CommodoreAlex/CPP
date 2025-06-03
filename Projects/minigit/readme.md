# MiniGit: Remaking Git's Core Functionality in C++

## Overview
**MiniGit** is a project where I recreated Git's core functionality using **C++**, implementing essential commands such as `status`, `commit`, `add`, `log`, `init`, and `checkout`. This project provided deep insights into version control mechanics, file tracking, and commit history management. For project management, I utilized **CMake**, ensuring a structured build system.

## Implemented Features
- **`status`** - Displays the current state of tracked/untracked files.
- **`commit`** - Saves changes with a unique identifier.
- **`add`** - Stages new or modified files for commit.
- **`log`** - Shows the history of commits.
- **`init`** - Initializes a new repository.
- **`checkout`** - Switches between different commit states.

## Learning Takeaways
- **Deepened Understanding of Git**: Implementing core Git features enhanced my knowledge of how version control systems work under the hood.
- **Data Structures & Algorithms**: Managed file hashes, implemented trees, and optimized commit history storage.
- **File System Interaction**: Learned how to handle file operations efficiently in C++.
- **CMake for Build Management**: Understood dependency resolution, project structuring, and automated compilation workflows.
- **Error Handling & Robustness**: Designed a reliable system that gracefully handles edge cases in version tracking.

MiniGit was a great exercise in **low-level systems programming** and gave me an appreciation for the complexity of Git's internals.

# Maze Traversal

This program mimics how robots explore and learn from their surroundings. By visualizing each decision point, it demonstrates the principles of exploration, backtracking, and pathfinding that are crucial in developing intelligent systems capable of solving real-world navigation problems.

## Overview
This program implements a maze traversal algorithm using __depth-first search (DFS)__ with a stack. It attempts to find a path from the entrance to the exit of a predefined maze by exploring each direction and backtracking if a dead end is encountered.

## Features
- Visualize the maze traversal step-by-step
- Use a 12x12 character array to represent the maze
- Implement an iterative algorithm for maze traversal using a stack
- Display the result (success or failure) of the traversal

## How to Use
1. Compile the C++ file using a C++ compiler.
2. Run the compiled executable.
3. The program will automatically start traversing the maze.
4. Press Enter after each step to continue the traversal.
5. The program will display a success message if the maze is solved, or a failure message if it is unsolvable.

## Maze Representation
- `#` represents walls
- `.` represents open paths
- `X` represents the current position
- `*` represents visited paths

**Starting Position:** (2, 0)

**Exit Position:** (4, 11)

## Note
This program uses a predefined maze. To use a different maze, modify the maze array in the `main()` function.

## Requirements
- C++ compiler
- Standard C++ libraries

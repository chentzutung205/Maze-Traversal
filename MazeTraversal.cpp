#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAZE_SIZE = 12;
#define WALL '#'          // A wall in the maze
#define PATH '.'          // A walkable path
#define VISITED '*'       // A visited cell
#define CURRENT 'X'       // The current position of the solver

struct Position {
  int x, y;
  Position(int x, int y) : x(x), y(y) {}  // Constructor to initialize the coordinates

  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;  // Check if two positions are equal
  }

  bool operator!=(const Position &other) const { return !(*this == other); }  // Check if two positions are not equal
};

const Position START(2, 0);
const Position END(4, 11);
const vector<Position> DIRECTIONS = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Up, Right, Down, Left

void printMaze(const vector<vector<char>> &maze, const Position &current) {
  for (int i = 0; i < MAZE_SIZE; ++i) {
    for (int j = 0; j < MAZE_SIZE; ++j) {
      if (Position(i, j) == current) {
        cout << CURRENT << ' ';
      } else if (Position(i, j) == START) {
        cout << 'S' << ' ';
      } else if (Position(i, j) == END) {
        cout << 'E' << ' ';
      } else {
        cout << maze[i][j] << ' ';
      }
    }
    cout << '\n';
  }
  cout << "Press Enter to continue...\n";
  cin.get();
}

bool isValid(const Position &p, const vector<vector<char>> &maze) {
  return p.x >= 0 && p.x < MAZE_SIZE && p.y >= 0 && p.y < MAZE_SIZE &&  // The position must be inside the maze
         maze[p.x][p.y] != WALL && maze[p.x][p.y] != VISITED;           // The position cannot be a wall or a visited cell
}

bool solveMaze(vector<vector<char>> &maze) {
  stack<Position> path;  // Store the positions the solver has visited
  path.push(START);

  while (!path.empty()) {
    Position current = path.top();

    if (current == END) {
      printMaze(maze, current);
      cout << "Success! Maze solved at (" << END.x << ", " << END.y << ")!\n";
      return true;
    }

    bool foundPath = false;
    for (const auto &dir : DIRECTIONS) {
      Position next(current.x + dir.x, current.y + dir.y);
      if (isValid(next, maze) || next == END) {
        path.push(next);
        if (next != END) {
          maze[next.x][next.y] = VISITED;
        }
        printMaze(maze, next);
        foundPath = true;
        break;
      }
    }

    if (!foundPath) {
      // Print dead-end message when no valid moves
      cout << "Oh no! This is a dead end at (" << current.x << ", " << current.y << ").\n";

      // Pop the stack to backtrack
      path.pop();

      if (!path.empty()) {
        // After popping, print the backtracking message and show the previous position
        printMaze(maze, path.top());
        cout << "Backtracking...\n";
      } else {
        printMaze(maze, current);
        cout << "Oh no! The maze is unsolvable.\n";
        return false;  // Maze unsolvable
      }
    }
  }

  return false;
}

int main() {
  vector<vector<char>> maze = {
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
      {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
      {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
      {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
      {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
      {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
      {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

  cout << "Welcome to Maze Traversal!\n\n";
  solveMaze(maze);
  return 0;
}

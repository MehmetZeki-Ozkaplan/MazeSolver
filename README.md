# MazeSolver
This project is a C++ application that uses a Depth-First Search (DFS) algorithm to solve a maze. The application reads a map file, identifies the start and end points, and attempts to find a path between these points. The solution is displayed step-by-step on the screen.

- Features

  Map Reading: Reads a map file and imports the map data.
  Start and End Point Detection: Automatically detects start and end points on the map.
  Depth-First Search (DFS): Uses DFS algorithm to find a solution.
  Step-by-Step Display: Shows the solution process step-by-step on the screen.
  Impassable Locations Notification: Notifies the user of impassable or blocked areas.

  - Installation and Usage
    Requirements

  A C++11 or later standard compatible compiler (e.g., g++ or clang++).

- Installation
  Download the Project
  Clone or download the project from GitHub:

      git clone https://github.com/your_username/maze-solver.git
      cd maze-solver

- Compilation and Execution
    Compile the Project
    Use a C++ compiler to build the project:

      g++ -o maze_solver main.cpp

This command compiles main.cpp and generates an executable named maze_solver.

- Run the Application
  Execute the compiled program:

      ./maze_solver

The program will read the Map.txt file and attempt to find a path between the start and end points on the map.

-Usage
When you run the program:
The start and end points on the map are automatically detected.
The Depth-First Search (DFS) algorithm is used to find a path between these points.
The solution process is displayed on the screen step-by-step. The current position and impassable locations are indicated.

- Contributing
To contribute:
Fork: Fork the repository on GitHub.
Add Features or Fix Bugs: Make changes in your forked repository.
Submit a Pull Request: Create a pull request with your changes.
Thank you for your contributions!

- License
This project is licensed under the MIT License. See the LICENSE file for details.

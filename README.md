# MazeSolver
This project is a C++ application that uses a Depth-First Search (DFS) algorithm to solve a maze. The application reads a map file, identifies the start and end points, and attempts to find a path between these points. The solution is displayed step-by-step on the screen.

## Contents

- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Maze Solver is a console-based application designed to solve mazes by finding a path from the entry to the exit using depth-first search (DFS) algorithm. It reads the maze structure from a file, identifies the start and end points, and visualizes the step-by-step process of solving the maze. This project is an excellent demonstration of basic algorithms and data structures, particularly stacks, and provides a clear understanding of how DFS can be applied to solve real-world problems.

## Features

  Map Reading: Reads a map file and imports the map data.
  Start and End Point Detection: Automatically detects start and end points on the map.
  Depth-First Search (DFS): Uses DFS algorithm to find a solution.
  Step-by-Step Display: Shows the solution process step-by-step on the screen.
  Impassable Locations Notification: Notifies the user of impassable or blocked areas.

## Project Structure

    maze-solver/
    ├── README.md
    ├── LICENSE
    ├── src/
    │   ├── main.cpp
    │   ├── maze_solver.cpp
    │   ├── maze_solver.h
    ├── data/
    │   └── Map.txt
    ├── build/
    └── docs/


  - Installation and Usage
    Requirements

  A C++11 or later standard compatible compiler (e.g., g++ or clang++).

## Installation
  Download the Project
  Clone or download the project from GitHub:

      git clone https://github.com/MehmetZekii/MazeSolver.git
      
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

## Usage
When you run the program:
The start and end points on the map are automatically detected.
The Depth-First Search (DFS) algorithm is used to find a path between these points.
The solution process is displayed on the screen step-by-step. The current position and impassable locations are indicated.

## Documentation
    ################### #############################
    #                        ########################
    ####### #########################################
    ####### #########################################
    #                                               #
    ######################################## ###### #
    #####     #####  ####  ######      #####  ####  #
    #####  ########  ####  ######  ##  #####  ####  #
    #####     #####  ####  ######    #######  ####  #
    ########  #####  ####  ######  ##  #####  ####  #
    #####     #####        ######      #####        #
    ############################################## ##
    ######### ####  ######## ########## ########## ##
    #     ### ####  ##    ## ##########     ###    ##
    ##### ### ####  ## ## ## ########## ###  ## #####
    ##### ### ####  ##### ## ########## ####    #####
    ##### ###  ###        ## ###        #############
    ##### #### ################# ####################
    #####                        ####################
    ##### ###########################################

## Contributing
To contribute:
Fork: Fork the repository on GitHub.
Add Features or Fix Bugs: Make changes in your forked repository.
Submit a Pull Request: Create a pull request with your changes.
Thank you for your contributions!

## License
This project is licensed under the MIT License. See the LICENSE file for details.

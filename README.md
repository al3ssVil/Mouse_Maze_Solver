# Mouse Pathfinding (Soarece si Branza)

A C++ program that finds the shortest path for a mouse to reach a piece of cheese on a grid using the Breadth-First Search (BFS) algorithm. The grid is represented by a matrix, and the mouse and cheese are placed at specific positions.

## Description

This project is a simulation of a mouse navigating a maze (grid) to reach a piece of cheese. The maze is represented by a matrix where:

- `0` represents an open space where the mouse can move.
- `-1` represents a wall that the mouse cannot pass through.

The program reads the maze from a file `date.txt`, where it loads the maze dimensions, the maze itself, and the starting position of the mouse and the cheese. Using the BFS algorithm, the program finds the shortest path from the mouse to the cheese and prints the path.

If the mouse can reach the cheese, the program will output the entire path the mouse takes. If the cheese is unreachable, the program will display a message indicating that it's not possible to reach the cheese.

There are no external dependencies, and it can be compiled and run on any system with a C++ compiler.

## Input Format (date.txt)

The file `date.txt` should have the following format:

    
    n m 
    matrix[0][0] matrix[0][1] ... matrix[0][m-1] 
    matrix[1][0] matrix[1][1] ... matrix[1][m-1] 
    ... 
    matrix[n-1][0] matrix[n-1][1] ... matrix[n-1][m-1] 
    soarece_x soarece_y 
    branza_x branza_y
    
  Where:
- `n` is the number of rows of the matrix.
- `m` is the number of columns of the matrix.
- `matrix[i][j]` represents each cell in the maze.
- `soarece_x, soarece_y` is the position of the mouse.
- `branza_x, branza_y` is the position of the cheese.

Example of `date.txt`:

![image](https://github.com/user-attachments/assets/9b13b24a-0548-4a40-8bb3-d2866ef3f000)

Where:
- The mouse starts at position `(4, 4)` (0-based index).
- The cheese is at position `(1, 3)` (0-based index).
- `-1` represents walls, and `0` represents open spaces.

## Example Gameplay

1. **Input**: The program reads the maze and starts at the mouse's position `(4, 4)` and searches for the shortest path to the cheese at position `(1, 3)`.

2. **Pathfinding**: The program uses the BFS algorithm to explore all possible paths from the mouse to the cheese, marking each visited cell with the number of steps taken to reach it.

3. **Output**: If the mouse can reach the cheese, the program prints the entire path from the mouse's starting position to the cheese's position. If the mouse cannot reach the cheese, it will display the message:
    ```
    Nu se poate ajunge la branza
    ```

    If the path is found, the program will output the coordinates of each step, starting from the cheese's position and tracing the path back to the mouse's position:
    ```
    Drumul este
    1 3
    1 4
    2 4
    2 5
    3 5
    4 5
    4 4
    ```

4. **Error Handling**: If the mouse cannot reach the cheese, the program will output:
    ```
    Nu se poate ajunge la branza
    ```

## How It Works

1. **Maze Input**: The program reads the maze configuration from the file `date.txt` and stores it in a matrix. It also stores the initial positions of the mouse and the cheese.
   
2. **Breadth-First Search (BFS)**: The BFS algorithm explores all possible paths from the mouse to the cheese. It visits all neighboring cells, marking them with the number of steps taken to reach them. If the cheese is found, the path is traced back by checking neighboring cells with decreasing step values.

3. **Displaying the Path**: If a valid path exists, the program will display the path by tracing it from the cheese's position to the mouse's position. If no path is found, the program will output a message stating that the cheese is unreachable.


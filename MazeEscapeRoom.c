#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAZE_SIZE 10
#define PLAYER_SYMBOL 'P'
#define WALL_SYMBOL '#'
#define PATH_SYMBOL '.'
#define EXIT_SYMBOL 'E'

typedef struct {
    int row;
    int col;
} Position;

void generateMaze(char maze[][MAZE_SIZE]) {
    // Maze generation logic (simplified for demonstration)
    // Initialize walls and paths
    int i,j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = (rand() % 2 == 0) ? WALL_SYMBOL : PATH_SYMBOL;
        }
    }

    // Set player's starting position
    maze[0][0] = PLAYER_SYMBOL;
    // Set exit position
    maze[MAZE_SIZE - 1][MAZE_SIZE - 1] = EXIT_SYMBOL;
}

void displayMaze(char maze[][MAZE_SIZE]) {
	int i,j;
    for ( i = 0; i < MAZE_SIZE; i++) {
        for ( j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char maze[MAZE_SIZE][MAZE_SIZE];
    generateMaze(maze);
	
    int currentRow = 0, currentCol = 0;

	printf(" MAZE ESCAPE ROOM\n\n");
    while (maze[currentRow][currentCol] != EXIT_SYMBOL) {
        displayMaze(maze);
        printf("Enter your move (u/d/l/r): ");
        char move;
        scanf(" %c", &move);

        int newRow = currentRow, newCol = currentCol;

        switch (move) {
            case 'u':
                newRow--;
                break;
            case 'd':
                newRow++;
                break;
            case 'l':
                newCol--;
                break;
            case 'r':
                newCol++;
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }

        if (newRow < 0 || newRow >= MAZE_SIZE || newCol < 0 || newCol >= MAZE_SIZE) {
            printf("Invalid move! You went out of bounds.\n");
            continue;
        }

        if (maze[newRow][newCol] == WALL_SYMBOL) {
            printf("Invalid move! You hit a wall.\n");
            continue;
        }

        // Update player position
        maze[currentRow][currentCol] = PATH_SYMBOL;
        currentRow = newRow;
        currentCol = newCol;
        maze[currentRow][currentCol] = PLAYER_SYMBOL;
    }

    displayMaze(maze);
    printf("Congratulations! You escaped the maze!\n");

    return 0;
}


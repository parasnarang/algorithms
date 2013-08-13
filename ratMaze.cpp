/* Rat in a maze problem using backtracking
 * http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze/
 *
 */
#include <iostream>
using namespace std;

// Maze size
#define N 4

void printSolution(int sol[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool isSafe(int maze[N][N], int x, int y){
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]){
    if(x == N-1 && y == N-1){
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y) == true){
        sol[x][y] = 1;

        if (solveMazeUtil(maze, x+1, y, sol) == true)
            return true;

        if (solveMazeUtil(maze, x, y+1, sol) == true)
            return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}

bool solveMaze(int maze[N][N]){
    int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if(solveMazeUtil(maze, 0, 0, sol) == false){
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol);
    return true;
}

int main(){
    int maze[N][N]  =  { {1, 0, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}

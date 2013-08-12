/* Knight's Tour problem using backtracking
 * http://en.wikipedia.org/wiki/Knight%27s_tour
 *
 */
#include <iostream>
using namespace std;

#define N 8
 
int isSafe(int x, int y, int sol[N][N]){
    if ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
        return 1;
    return 0;
}
 
void printSolution(int sol[N][N]){
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]){
   int k, next_x, next_y;
   if (movei == N*N)
       return true;
 
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y, sol))
       {
         sol[next_x][next_y] = movei;
         if (solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove) == true)
             return true;
         else
             sol[next_x][next_y] = -1;// backtracking
       }
   }

   return false;
}
 
bool solveKT(){
    int sol[N][N];
 
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
 
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
 
    sol[0][0]  = 0;
 
    if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == false){
        printf("Solution does not exist");
        return false;
    }
    else
        printSolution(sol);
 
    return true;
}

int main(){
    solveKT();
    return 0;
}

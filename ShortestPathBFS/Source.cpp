#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int srcX, int srcY, int DesX, int DesY,int &minDistance, int distance, int rows,int columns)
{

    if (srcX >= rows || srcX<0 || srcY >= columns || srcY < 0 || visited[srcX][srcY] || grid[srcX][srcY] == 0)
    {
        //if any of these conditions are satisfied, simply return nothing :)
        return ; //you dont have to create another fucntion to get a true or false, although that's clean coding
    }



    if (srcX == DesX && srcY == DesY) //if the destination is reached, make the minDistance the one with the lower vlaue between distance and minDistance. In truth minDistance is set to INT_MAX for now
    {
        minDistance = min(distance, minDistance); //if the destination is reached, give us the minDistance
        //this can only happen with min function
    }

    visited[srcX][srcY] = true; //this node is visited now!

    DFS(grid, visited, srcX + 1, srcY, DesX, DesY, minDistance, distance + 1, rows, columns); //increasing the distance
    DFS(grid, visited, srcX -1, srcY, DesX, DesY, minDistance, distance + 1, rows, columns); //increasing the distance
    DFS(grid, visited, srcX, srcY+1, DesX, DesY, minDistance, distance + 1, rows, columns); //increasing the distance
    DFS(grid, visited, srcX, srcY-1, DesX, DesY, minDistance, distance + 1, rows, columns); //increasing the distance


    //calling 4 times in recursion for 4 directions
    //now make use of the backtracking -> this is something new for me that is making the visited[srcX][srcY]=false;

   visited[srcX][srcY] = false;

}


int shortestPath(vector<vector<int>>& grid, pair<int, int> source,
    pair<int, int> destination) {

    int rows = grid.size();
    int columns = grid[0].size();


    int minDistance = INT_MAX; //using it to set the highest value since we will be using another distance as well
    vector<vector<bool>> visited(rows, vector<bool>(columns, false)); //this is the initialization

    if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
    {

        return -1;
    }

    DFS(grid, visited, source.first, source.second, destination.first, destination.second, minDistance, 0, rows, columns);


    if (minDistance == INT_MAX)
    {
        return -1;
    }

    return minDistance;

}

int main(void)
{

    vector<vector<int>> grid = { {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1} };

    pair<int, int> source = { 0,0 };
    pair<int, int> destination = { 3,4 };

    int SP = shortestPath(grid, source, destination);

}
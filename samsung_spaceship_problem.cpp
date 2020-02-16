/*
1: This cell has a coin.
2: This cell has an enemy.
0: It contains nothing.
The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins.
Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
At each time, the non-highlighted part of the grid will move down by one unit.
We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.
Find maximum number of coins that we can collect.
                           0 1 0 2 0
                           0 2 2 2 1
                           0 2 1 1 1
                           1 0 1 0 0
                           0 0 1 2 2
                           1 1 0 0 1
                           x x S x x 

*/

#include <iostream>
using namespace std;
int result=0,used=0;
int main() 
{
    int row=11,col=5;
    char grid[row][col];
    
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>grid[i][j];
    
    int s_row = row-1;   //position of spaceship
    int s_col = col/2;
    
    void dfs(int row, int col, char *grid, int x, int y, int cursum, int bomb_used);
    
    dfs(row,col,(char *)grid, s_row, s_col, 0, 0);
    
    cout<<"Maximum coin is :- "<< result<<endl;
    cout<<"Bomb used - "<<used;
}

void dfs( int row, int col, char *grid, int x, int y, int cursum, int bomb_used)
{
    void use_bomb(int row, int col, char* grid, int x, int y);
    void restore(int row, int col, char* grid, int x, int y);
    bool isSafe(int row, int col, char* grid, int x, int y);
    
    if(x<0)  //reached end of the line
        return;
      
    if(*(grid+ x*col + y) == '1')
    {
            cursum++;
            result=max(cursum,result);
    }
    //for left move
    if(isSafe(row,col,(char *)grid, x-1, y-1))
        dfs(row,col, (char *)grid, x-1, y-1,cursum,bomb_used);
            
    // for no move
    if(isSafe(row,col,(char *)grid, x-1, y))
            dfs(row,col, (char *)grid, x-1, y,cursum, bomb_used);
            
   // for right move
    if(isSafe(row,col,(char *)grid, x-1, y+1))
            dfs(row,col, (char *)grid, x-1, y+1, cursum,bomb_used);
     
    if(bomb_used==0)  //surrounded by enemy, need to use bomb
    {
        use_bomb(row,col, (char *)grid, x,y);
        bomb_used=1;
        //for left move
        if(isSafe(row,col,(char *)grid, x-1, y-1))
            dfs(row,col, (char *)grid, x-1, y-1,cursum,bomb_used);
            
        // for no move
        if(isSafe(row,col,(char *)grid, x-1, y))
            dfs(row,col, (char *)grid, x-1, y,cursum, bomb_used);
            
        // for right move
        if(isSafe(row,col,(char *)grid, x-1, y+1))
            dfs(row,col, (char *)grid, x-1, y+1, cursum,bomb_used);
            
        restore(row,col, (char *)grid, x,y);   //restoring the original state of grid
    }

}
// Function that will use the bomb and destroy enemies in 5x5
void use_bomb(int row, int col, char* grid, int x, int y)
{
    used++;
    int i=(x-5>=0)?x-5:0;
    
    for(; i<x; i++)
	    for(int j=0; j<col; j++)
	        if(*(grid + i*col + j)=='2')
	            *(grid + i*col + j)='9';
}
// Function that will restore the original grid before bomb.
void restore(int row, int col, char* grid, int x, int y)
{
     int i=(x-5>=0)?x-5:0;
    for(; i<x; i++)
	    for(int j=0; j<col; j++)
	        if(*(grid + i*col + j)=='9')
	            *(grid + i*col + j)='2';	            
}
// Function to check if the move is safe
bool isSafe(int row, int col, char* grid, int x, int y)
{
     if(x>=0 && y>=0 && y<col)
         if(*(grid+x*col + y) != '2')  
           return true;
    
    return false;
}

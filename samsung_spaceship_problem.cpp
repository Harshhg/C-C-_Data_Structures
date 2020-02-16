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
int row, col;
int result=0;
int used=0;
int main() 
{
     row=7;
     col=5;
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
    if(x<0)  //reached end of the line
        return;
      
    if(*(grid+ x*col + y) == '1')
    {
            cursum++;
            result=max(cursum,result);
    }
    int bomb=0;
    //for left move
    if(x-1 >=0 && y-1>=0)
        if(*(grid+(x-1)*col + y-1) != '2')  //if move is safe
            dfs(row,col, (char *)grid, x-1, y-1,cursum, 0);
        else
            bomb++;
            
    // for no move
    if(x-1 >=0 && y>=0)
        if(*(grid+(x-1)*col + y) != '2')  //if move is safe
            dfs(row,col, (char *)grid, x-1, y,cursum, 0);
        else
            bomb++;
            
   // for right move
    if(x-1 >=0 && y+1<col)
        if(*(grid+(x-1)*col + y+1) != '2')  //if move is safe
            dfs(row,col, (char *)grid, x-1, y+1, cursum, 0);
        else
            bomb++;
    
    
    if(bomb==3 && bomb_used==0)  //surrounded by enemy, need to use bomb
    {
        use_bomb(row,col, (char *)grid, x,y);
        dfs(row,col, (char *)grid, x, y, cursum, 1);
        restore(row,col, (char *)grid, x,y);   //restoring the original state of grid
    }
    
}
void use_bomb(int row, int col, char* grid, int x, int y)
{
    used++;
    int i=(x-5>=0)?x-5:0;
    
    for(; i<row; i++)
	    for(int j=0; j<col; j++)
	        if(*(grid + i*col + j)=='2')
	            *(grid + i*col + j)='9';
	 cout<<"USED"<<endl;         	            
}
void restore(int row, int col, char* grid, int x, int y)
{
    int i=(x-5>=0)?x-5:0;
    
    for(; i<row; i++)
	    for(int j=0; j<col; j++)
	        if(*(grid + i*col + j)=='9')
	            *(grid + i*col + j)='2';          
}

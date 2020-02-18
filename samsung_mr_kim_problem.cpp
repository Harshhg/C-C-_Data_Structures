/*
Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home.
Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (-1<x<101, -1<y<101) . 
The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x;
for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. 
You should plan an optimal way to visit all the N customers and return to his among all the possibilities.

You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10.
Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home.
Your program only have to report the distance of a (the) shortest path.

Input format - 
You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers,
and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. 
Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.

Input - 
5
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36

Output - 
200
304
366

*/
// Applied Travelling salesperson problem concept...

#include <iostream>
using namespace std;
// Function that will perform travelling salesman algorithm using backtracking
void tsp( int *graph, bool vis[], int currPos,int n, int count, int cost, int& ans) 
{
    if (count == n) 
    { 
        // adding cost of last customer to the office ( graph[currpos][1] )since destination is on 1st column
        ans = min(ans, cost + *(graph+ currPos*(n+1) + 1));    
        return; 
    } 
    for (int i = 0; i<=n; i++) 
    { 
        if(i==1)      // Skipping the 1st row in graph, because it is the destination(office).
            continue;
        if (!vis[i]) 
        { 
            vis[i] = true; 
            tsp(graph, vis, i, n, count + 1,cost + *(graph+currPos*(n+1) + i), ans);
            vis[i] = false; 
        } 
    } 
}
int main() 
{
    int tc = 3; //number of test cases
    while(tc--)
    {
        int num;  //no of customers
        cin>>num;

        //num+2 because 5 customers and 1 office, 1 home...
        int x1[num+2], x2[num+2];  //creating 2 arrays for x1 and x2 coordinates..
        
        for(int i=0;i<=num+1; i++)
        {
            cin>>x1[i];
            cin>>x2[i];
        }
        
        int grid[num+2][num+2];  //creating graph matrix
        
        //calculating distance and putting in graph
        for(int i=0; i<=num+1; i++)
            for(int j=0; j<=num+1; j++)
                grid[i][j] = abs(x1[i]-x1[j]) + abs(x2[i]-x2[j]);
            
        //Creating a visited array        
         bool vis[num+2];
         for (int i = 0; i <=num+1; i++) 
            vis[i] = false; 
  
        vis[0] = true; //Starting with the 1st node.
        int ans = 9999999; 
        //function called
        tsp((int *)grid , vis, 0, num+1, 1, 0, ans); 
        cout << ans<<endl; 
    }
	return 0;
}

             
         


/*
Given a graph print either of the set of the vertices that are colored with the same color. And if the graph is not bipartite print “-1”. Test cases also included the cases when a graph is not connected. 
*/

#include <iostream>
using namespace std;
#define V 5
int color[V];
bool check(int G[][V])
{
    for(int i=0; i<V; i++)
        color[i]=-1;
        
    color[0]=1;
    
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(G[i][j]==1)
                {
                   if(color[j]==-1)
                        color[j]= 1-color[i];
                    else if(color[j]==color[i])
                       return false;
                }
        }
    }
    return true;
}

int main() 
{
    int G[][V] = 
    {
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,0},
        {0,1,0,0,0}
    };
	if(check(G))
	    cout<<"Bipartite Graph!";
	else
	    cout<<"Not Biparatite..";
	 
	 cout<<endl;   
	 for(int i=0; i<V; i++)
	    if(color[i]==1)
	        cout<<i<<"-";
}

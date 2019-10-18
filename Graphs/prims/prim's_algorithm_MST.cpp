#include <iostream>
#include <climits>
using namespace std;
#define V 5   // number of vertices in a graph.

// function to print the final results
void print_result(int parent[], int key[])
{
    cout<<"Edge \tWeight\n";
    for(int i=1; i<V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<key[i]<<endl;
}

// Function to find the minimum key value( weight) and return the index of it.
int min_key(int key[] , bool visited_set[])
{
    int min = INT_MAX;
    int min_index;
    for (int i=0; i<V; i++)
        if(key[i] < min  && visited_set[i] == false)
            min = key[i],min_index = i;
    return min_index;
}


// Prim's algorithm
void prims_algo(int graph[V][V])
{
int parent[V];         // will store the parents of the vertices, to later print the results.
int key[V];            // will store the weight of edge from one vertices to another. (we will choose minimum one)
bool visited_set[V];    // will store the set of vertices that are visited.

// Initializing all keys with infinite values and visited set with false.
for (int i=0; i < V; i++)
    key[i] = INT_MAX, visited_set[i]=false;

    
// Starting the algo.
key[0] = 0 ;        //initializing first key as 0
parent[0] = -1;     // first one is always root.

// Here we go
for (int count=0; count < V; count++)
{
    // First we pick the minimum key value vertex..
    int u = min_key(key,visited_set);   // returns the index of the minimum weight vertex.
    visited_set[u] = true;              // Marking that vertex as visited.
    // Now we will look for the adjacent of the visited vertex to find more paths.
    for(int v = 0;  v < V ; v++)
    {
        if(graph[u][v] && visited_set[v] == false   &&    graph[u][v]  < key[v] )  // checking if weight > 0(not a self node),   node is not visited,    path to another node is minium than other paths
            {
                parent[v] = u;   //  setting the parent of the node, from where we come to this node.
                key[v] = graph[u][v];   // updating minimum path (weight) to that node.
            }
    }
}
// Finally printing the results
    print_result(parent, key);
}

// Main function
int main()
{
int graph[V][V] =     { { 0, 2, 0, 6, 0 },          
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  

prims_algo(graph);   
return 0;
}
// OUTPUT
/*
Edge 	Weight
0 - 1 	2
1 - 2 	3
0 - 3 	6
1 - 4 	5

*/

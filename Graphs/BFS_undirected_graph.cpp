#include <iostream>
#include<vector>
#include<list>
using namespace std;

void addEdge(vector<int> adj[], int u , int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex "<< v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
        
    } 
} 
void BFS(vector<int> adj[], int S)
{
    int cur;
list<int>queue;
queue.push_back(S);
int ar[5];

/* Initializing visited array with 0
 0 - not visited
 1 - visited
*/
for(int i=0; i<5; i++)
ar[i]=0;



while(!queue.empty())
{
    cur = queue.front();
    queue.pop_front();
    
    if(ar[cur]==0)   // Checking if current node is already visited or not.
    {for(auto x: adj[cur])
        queue.push_back(x);
    
    cout<<cur<<"-";
    }
    ar[cur]=1;  // Marking cuurent node as visited.
}
}
int main() 
{
    int V=5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3); 
    addEdge(adj,3,4); 
    printGraph(adj,V);
    cout<<"\nBFS of this graph is : \n";
    BFS(adj,0);
}

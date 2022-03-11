#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    We traverse every node only once - N
    For each node we call DFS to it's unvisited adjacent nodes - E.
    Time Complexity : O(N+E)
*/
void dfs(int node, vector<int> &vis, vector<int> adj[],vector<int> &dfs_path){

    vis[node]=1;               // mark as visited
    dfs_path.push_back(node);  // add node to path
    
    // call dfs for all it's unvisited adjacent nodes
    for(int i:adj[node]){

        if(!vis[i])      
            dfs(i,vis,adj,dfs_path);          
    }
}
int main(){
    fastio();

    int n,edges;                // nodes,edges
    cin>>n>>edges;
    vector<int> adj[n+1];       // adjacency list
    vector<int> vis(n+1,0), dfs_path;   
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a); // comment this line for directed graph
    }


    for(int node=1;node<=n;node++){         // traverse through all components

        if(!vis[node]){            
            dfs(node,vis,adj,dfs_path);
        }
    }

    for(auto e:dfs_path)
        cout<<e<<sp;     

    return 0;
}
/*
Output:
5 5
1 2
2 5
2 3
5 4
4 3
1 2 5 4 3
*/
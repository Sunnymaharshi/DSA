#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    Since it is directed graph, a->b is different from b->a.
    We can't check for cycle with single vis array.
    we use another array to check if node is already visited in 
    same dfs call or not.
    if node is already visited in same dfs call then it has cycle.
    Time Complexity : O(N+E)
*/

bool checkCycle_DFS(int node,vector<int> &vis,vector<int> &dfs_vis,vector<int> adj[]){

    vis[node] = 1;                  // mark it as visited
    dfs_vis[node] = 1;              // mark it as visited for this dfs call

    for(int i:adj[node]){

        if(!vis[i]){                // not visited
            // if any of adjacent node detect cycle
            // stop checking remaining adjacent nodes
            if(checkCycle_DFS(i,vis,dfs_vis,adj))
                return true;
        }
        // node is visited and in same dfs call
        else if(dfs_vis[i])
            return true;        
    }
    // before ending this call, mark it as unvisited in dfs_vis
    dfs_vis[node] = 0;

    return false;
}

int32_t main() {
    fastio();

    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n+1,0), dfs_vis(n+1,0);           // all nodes are colored with -1
    bool cycle = false;

    for(int node=1;node<=n;node++){      // traverse through all components
    
        if(vis[node]==0){            // node is not visited
    
            // if any component has cycle, stop checking remaining components        
            if(checkCycle_DFS(node,vis,dfs_vis,adj)){
                cycle=true;
                break;
            }
        }
    }

    if(cycle)
        cout<<"Graph has Cycle";
    
    else
        cout<<"Gragh has no Cycle";
    
    return 0;
}
/*
Output:
5 5
1 2
2 3
3 1
3 4
4 5
Graph has Cycle
*/
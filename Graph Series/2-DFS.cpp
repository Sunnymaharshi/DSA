#include<iostream>
using namespace std;
#include<vector>
void dfs(int node, vector<int> &vis, vector<int> adj[],vector<int> &dfs_path){
    vis[node]=1;               // mark as visited
    dfs_path.push_back(node);  // add node to path
    for(int i:adj[node]){
        if(!vis[i]){        
            dfs(i,vis,adj,dfs_path);  // call dfs for all unvisited adjacent nodes
        }
    }
}
int main(){
    int n,edges; //nodes,edges
    cin>>n>>edges;
    vector<int> adj[n+1]; //adjacency list
    vector<int> vis(n+1,0), dfs_path; //visited array
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a); // comment this line for directed graph
    }
    for(int node=1;node<=n;node++){
        if(!vis[node]){            // for all components
            dfs(node,vis,adj,dfs_path);
        }
    }
    for(auto e:dfs_path)
        cout<<e<<" ";     //print path
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
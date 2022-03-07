#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(int n,int node,vector<int> &vis,vector<vector<int>> &adj, vector<int> &bfs_path){
    queue<int> q;
    q.push(node);               // add into queue
    vis[node]=1;                // mark as visited
    while(!q.empty()){
        int cur_node=q.front();    
        q.pop();         
        bfs_path.push_back(cur_node);     
        for(int i=1;i<=n;i++){
            if(adj[cur_node][i]==1 && vis[i]!=1){   // add all its unvisited adjacent nodes into queue
                q.push(i);
                vis[i]=1;       // mark as visited
            }
        }
    }
}
int main(){
    int n,edges;                     // nodes,edges
    cin>>n>>edges;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));  // adjacency matrix
    vector<int> vis(n+1,0);         //visited array
    vector<int> bfs_path; 
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;                // comment this line for directed graph
    }
    for(int node=1;node<=n;node++){          // for checking all components
        if(!vis[node]){                     // process node only if it is not visited
            bfs(n,node,vis,adj,bfs_path);
        }
    }
    for(auto i:bfs_path)
        cout<<i<<" ";
    
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
1 2 3 5 4
*/
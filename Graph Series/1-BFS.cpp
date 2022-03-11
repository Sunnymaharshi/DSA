#include<iostream>
#include<vector>
#include<queue>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/*
    We traverse every node only once - N
    For each node we traverse it's unvisited adjacent nodes - E.
    Time Complexity : O(N+E)
*/

void bfs(int n,int node,vector<int> &vis,vector<vector<int>> &adj, vector<int> &bfs_path){

    queue<int> Q;
    Q.push(node);               // add node into Queue
    vis[node]=1;                // mark as visited

    while(!Q.empty()){

        int cur_node = Q.front();    
        Q.pop();                                // remove node from Queue         
        bfs_path.push_back(cur_node);           // add it in our path

        for(int i=1;i<=n;i++){
            
            if(adj[cur_node][i]==1 && vis[i]!=1){ 
                // add all its unvisited adjacent nodes into Queue
                Q.push(i);          
                vis[i]=1;       // mark them as visited
            }
        }
    }
}
int main(){

    fastio();

    int n,edges;                     // nodes,edges
    cin>>n>>edges;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));  // adjacency matrix
    vector<int> vis(n+1,0);          // visited array
    vector<int> bfs_path; 

    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;                // edge a -> b
        adj[b][a]=1;                // edge b -> a,  for undirected graph
    }


    for(int node=1;node<=n;node++){          // traverse through all components

        if(!vis[node])                    
            bfs(n,node,vis,adj,bfs_path);
        
    }

    for(auto i:bfs_path)
        cout<<i<<sp;
    
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
#include<iostream>
#include<vector>
#include<queue>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    since it is undirected graph, we have edge between a->b and  b->a.
    if we find any adjacent node which is already visited and not previous
    adjacent node then it has cycle.
    since we're traversing breadth wise, if we reached a node which is already
    visited and it's not the previous adjacent node, then it must have visited by
    other node from other side of breadth, means it has a cycle.
    we carry a parent to make sure already visited node is not previous adjacent node.
    Time Complexity : O(N+E)
    it is same as BFS, since we're just added parent in queue.
*/
bool checkCycle_BFS(int node,vector<int> &vis,vector<int> adj[]){

    queue<pair<int,int>> Q;             // current node, parent
    Q.push({node,-1});                  // no parent       
    vis[node]=1;                        // mark as visited

    while(!Q.empty()){

        int cur_node=Q.front().first;
        int parent=Q.front().second;    
        Q.pop(); 

        // add all its unvisited adjacent nodes into queue
        // with it's parent i.e previous adjacent node
        for(int i : adj[cur_node]){

            if(vis[i]!=1){                 
                Q.push({i,cur_node});    // cur_node becomes parent for it's adjacent nodes.
                vis[i]=1;                // mark as visited
            }
            else if(i!=parent)           // if visited node is not it's parent, cycle exist.
                return true;              
        }
    }
    return false;
}
int main(){

    fastio();

    int n,edges;                //nodes,edges
    cin>>n>>edges;
    bool cycle=false;
    vector<int> adj[n+1];       // adjacency list
    vector<int> vis(n+1,0);     //visited array
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int node=1;node<=n;node++){          // traverse through all components

        if(!vis[node]){  
            // if any component has cycle, stop checking remaining components        
            if(checkCycle_BFS(node,vis,adj)){
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
4 5
5 4
Graph has Cycle
*/
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/* 
    since it is undirected graph, we have edge between a->b and  b->a.
    we go depth wise, as we deep if we find a node which is already visited
    and not the previous adjacent node then it has cycle.
    we carry parent to make sure visited node is not it's previous adjacent node.
    Time Complexity : O(N+E)
    It is same as DFS, we just add parent in function arguments.
*/
bool checkCycle_DFS(int node,int parent,vector<int> &vis,vector<int> adj[]){

    vis[node]=1;                // mark it as visited

    for(auto i:adj[node]){

        if(!vis[i]){
            // node will be parent for it's adjacent nodes
            // if we find cycle for any adjacent node, stop checking
            // for remaining adjacent nodes.
            if(checkCycle_DFS(i,node,vis,adj))
                return true;            
        }
        else if(i!=parent)      // already visited node is not previous adjacent node.
            return true;
    }
    return false;
}
int main(){
    fastio();

    int n,edges;                // nodes,edges
    bool cycle=false;
    cin>>n>>edges;
    vector<int> adj[n+1];       // adjacency list
    vector<int> vis(n+1,0);     // visited array
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int node=1;node<=n;node++){      // traverse through all components

        if(!vis[node]){  
            // no parent for first node  
            // if any component has cycle, stop checking remaining components        
            if(checkCycle_DFS(node,-1,vis,adj)){
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
// since it is undirected graph, we have edge between 1-2 and  2-1
// we carry parent to make sure visited node is not it's previous adjacent node
#include<iostream>
#include<vector>
using namespace std;
bool checkCycle(int node,int parent,vector<int> &vis,vector<int> adj[]){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            if(checkCycle(i,node,vis,adj))
                return true;
            
        }
        else if(i!=parent)
            return true;
    }
    return false;
}
int main(){
    int n,edges; //nodes,edges
    bool cycle=false;
    cin>>n>>edges;
    vector<int> adj[n+1]; //adjacency list
    vector<int> vis(n+1,0); //visited array
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int node=1;node<=n;node++){      // for all components
        if(!vis[node]){            
            if(checkCycle(node,-1,vis,adj)){
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
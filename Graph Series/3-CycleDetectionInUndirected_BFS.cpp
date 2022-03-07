#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool isCycle(int node,vector<int> &vis,vector<int> adj[]){
    queue<pair<int,int>> q;
    q.push({node,-1});   //no parent       
    vis[node]=1;               // mark as visited
    while(!q.empty()){
        int cur_node=q.front().first;
        int parent=q.front().second;    
        q.pop();         
        for(int i : adj[cur_node]){
            if(vis[i]!=1){                 // add all its unvisited adjacent nodes into queue
                q.push({i,cur_node});      //cur_node as parent for it's adjacent nodes.
                vis[i]=1;                  // mark as visited
            }
            else if(i!=parent)            //if visited node is not it's parent, cycle exist
                return true;              
        }
    }
    return false;
}
int main(){
    int n,edges; //nodes,edges
    cin>>n>>edges;
    bool cycle=false;
    vector<int> adj[n+1];  // adjacency list
    vector<int> vis(n+1,0); //visited array
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int node=1;node<=n;node++){          // for checking all components
        if(!vis[node]){          
            if(isCycle(node,vis,adj)){
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
#include<iostream>
#include<vector>
using namespace std;
// DFS
bool checkCycle(int node, int parent, vector<int> &vis,vector<int> graph[]){

    vis[node]=1;        // mark it as visited

    for(auto i:graph[node]){

        if(vis[i]==0){          // unvisited
            
            if(checkCycle(i,node,vis,graph)==true)
                return true;
        }
        else if(i!=parent)      // visited and it's not parent of current node
            return true;
    }
    return false;
}
int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    bool cycle = false;
    for(int node=1; node<=n; node++){               // to traverse all the components of the graph

        if(vis[node]==0){         // if node is not visited
            if(checkCycle(node,-1,vis,graph)==true){
                cycle=true;
                break;
            }
        }
    }
    if(cycle)   cout<<"Cycle";
    else        cout<<"No Cycle";

    return 0;
}
/*
Output:
5 4
1 2
3 4
4 5
5 3
Cycle
*/
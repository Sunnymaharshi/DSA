#include<iostream>
#include<vector>
using namespace std;
// DFS
bool checkCycle(int node, vector<int> &vis,vector<int> &pathvis, vector<int> graph[]){

    vis[node]=1;
    pathvis[node]=1;                // carry path

    for(auto i:graph[node]){
        if(vis[i]==0){              // unvisited
            if(checkCycle(i,vis,pathvis,graph)==true)
                return true;
        }
        else if(pathvis[i]==1)      // visited and it is in same path
            return true;
    }
    pathvis[node] = 0;              // when we go back, clear the path

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
    }
    vector<int> vis(n+1,0),pathvis(n+1,0);
    bool cycle = false;
    for(int node=1; node<=n; node++){               // to traverse all the components of the graph

        if(vis[node]==0){         // if node is not visited
            if(checkCycle(node,vis,pathvis,graph)==true){
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
4 4
1 2
2 3
1 4
4 3
No Cycle
Output:
4 4
1 2
2 3
3 4
4 1
Cycle
*/
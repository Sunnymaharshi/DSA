#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
// BFS
bool checkCycle(int node,vector<int> &vis, vector<int> graph[]){

    queue<pair<int,int>> Q;         // node, it's parent
    Q.push({node,-1});
    vis[node]=1;

    while(!Q.empty()){
        int newnode = Q.front().first;
        int par = Q.front().second;
        Q.pop();

        for(auto i: graph[newnode]){
            if(vis[i]==0){          // unvisited
                Q.push({i,newnode});
                vis[i]=1;
            }
            else if(i!=par)         // visited and it's not parent
                return true;
        }
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
            if(checkCycle(node,vis,graph)==true){
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
2 3
1 3
Cycle
*/
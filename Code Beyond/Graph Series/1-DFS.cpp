// Time Complexity O(n+n)
// since for every node, there is a for loop in DFS function
// max possible adjacent nodes are n
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void DFS(int node, int n,vector<int> &vis, vector<vector<int>> &graph){


    vis[node] = 1;                      // mark it as visited
    cout<<node<<" ";

    for(int i=1;i<=n;i++){              // for all adjacent nodes of node

        if(graph[node][i]==1){          

            if(vis[i]==0){              // if node is not yet visited, call DFS
                DFS(i,n,vis,graph);
            }

        }
    }

}

int main() {


    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>(n+1,0));      // adjacency matrix
    vector<int> vis(n+1,0);                                   // visited array
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;      // for undirected graph        
    }

    for(int node=1; node<=n; node++){               // to traverse all the components of the graph

        if(vis[node]==0){         // if node is not visited
            DFS(node,n,vis,graph);
        }
    }

    return 0;
}
/*
Output:
5 4
1 2
1 3
2 3
4 5
1 2 3 4 5 
*/
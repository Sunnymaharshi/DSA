// Time Complexity O(n + n)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int node, vector<int> &vis, vector<int> graph[]){

    vis[node]=1;        // mark node as visited
    queue<int> Q;
    Q.push(node);       // add it into queue

    while(!Q.empty()){

        int fnode = Q.front();          // retrieve 1st node in queue
        Q.pop();        // remove that node
        cout<<fnode<<" ";

        for(auto i:graph[fnode]){       // for all its unvisited adjacent nodes

            if(vis[i]==0){
                vis[i]=1;               // mark it as visited
                Q.push(i);              // add to queue
            }
        }
    }
}

int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];      // adjacency list
    vector<int> vis(n+1,0);                                   // visited array
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);   // for undirected graph        
    }

    for(int node=1; node<=n; node++){               // to traverse all the components of the graph

        if(vis[node]==0){         // if node is not visited
            BFS(node,vis,graph);
        }
    }


    return 0;
}
/*
Output:
5 5
1 2
1 5
2 3
3 4
3 5
1 2 5 3 4
*/
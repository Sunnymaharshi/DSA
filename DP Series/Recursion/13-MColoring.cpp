#include<iostream>
#include<vector>
#include<string.h>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
try every possible color for each node.
if we able to color all nodes with adjacents as different color 
we stop check further and return true
Time Complexity - O(N^M)
Space Complexity - O(N)[colors array] + O(N)[stack space of recursion]
*/
bool canColor(int node,int col,int color[],int n,bool graph[101][101]){

    for(int i=0;i<n;i++){
        // check all it's adjacent node 
        // if any of it has this color we cannot color node
        if(i!=node && graph[i][node]==1 && color[i]==col)
            return false;
    }

    return true;    // no adjacents have this color
}
bool graphColoring(int node,int color[],int m,int n,bool graph[101][101]){

    if(node==n){        // colored all nodes
        return true;
    }
    for(int col=1;col<=m;col++){                // try all colors
        if(canColor(node,col,color,n,graph)){

            color[node] = col;  // color the node
            if(graphColoring(node+1,color,m,n,graph)){  // check for next node

                return true;    // able to color the graph
            }
            color[node] = 0;    // remove the color
        }
    }
    return false;               // not able to color with any color
}
int32_t main() {
    fastio();

    int n,m,e;
    cin>>n>>m>>e;
    bool graph[101][101];
    for(int i=0;i<n;i++){
        memset(graph[i],0,sizeof(graph[i]));  // initialize adjacency matrix with 0s
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=1;      // since it is undirected graph
        graph[b-1][a-1]=1;      // edge from  a to b and b to a
    }

    int color[n]={0};
    if(graphColoring(0,color,m,n,graph))
        cout<<1;
    else
        cout<<0;
    return 0;
}
/*
Output:
4 3 5
0 1
1 2
2 3
3 0
0 2
1
*/
/*
if you able to color the graph with 2 colors such that no two adjacents
have same color then it has even len of cycle -> Bipartite Graph
*/
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;


bool checkBipartite(int node,int color,vector<int> &colors,vector<int> graph[]){

    colors[node] = color;
    for(auto i:graph[node]){
        if(colors[i]==-1){      // unvisited
            if(checkBipartite(i,!color,colors,graph)==false)
                return false;
        }
        else if(colors[i]==color){
            return false;           // same adjacent colors
        }
    }
    return true;                // able to color all nodes with adjacents different

}
bool checkBipartiteBFS(int node,int color,vector<int> &colors,vector<int> graph[]){

    colors[node] = color;
    queue<pair<int,int>> Q;
    Q.push({node,color});
    
    while(!Q.empty()){
        int nd = Q.front().first;
        int col = Q.front().second;
        Q.pop();
        for(auto i:graph[nd]){

            if(colors[i]==-1){              // unvisited
                colors[i]=!col;
                Q.push({i,!col});
            }
            else if(colors[i]==col){        // same adjacent node colors
                return false;
            }
        }
    }

    return true;                // able to color all nodes with adjacents different

}
int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1], colors(n+1,-1);     // -1 -> not visited
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool isBipartite = true;
    for(int i=1;i<=n;i++){                      // to traverse all components
        if(colors[i]==-1){          // not visited
            if(checkBipartite(i,0,colors,graph)==false){
                isBipartite=false;
                break;
            }
        }
    }
    if(isBipartite)
        cout<<"even length cycle";
    else
        cout<<"odd length cycle";
    return 0;
}
/*
Output:
4 4
1 2
2 3
3 4
4 2
odd length cycle
*/

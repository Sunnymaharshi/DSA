#include<iostream>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> tim, low_tim, vis;
int timr=0;
void DFS(int node, int parent, vector<int> graph[]){

    tim[node] = low_tim[node] = ++timr;
    vis[node] = 1;
    for(auto adj : graph[node]){

        if(adj == parent)
            continue;
        if(!vis[adj]){
            DFS(adj,node,graph);
            low_tim[node] = min(low_tim[node], low_tim[adj]);

            if(low_tim[adj] > tim[node]){         // never reach 
                cout<<adj<<"--"<<node<<nl;              
            }
        }
        else
            low_tim[node] = min(low_tim[node], low_tim[adj]);     
        
    }
}

int main() {

    fastio();
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vis.resize(n+1);
    tim.resize(n+1);
    low_tim.resize(n+1);
    DFS(1,-1,graph);
    return 0;
}
/*
Output:
5 5
1 2
2 3
3 4
4 5
3 5
3--2
2--1
*/
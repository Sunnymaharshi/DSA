#include<iostream>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void bellmanford(int n, vector<vector<int>> edges){

    vector<int> dist(n+1,INT_MAX);
    dist[1] = 0;                    // source

    for(int i=0;i<n-1; i++){        // atmost we need n-1 iterations

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;

        }
    }
    for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if( dist[u] + wt < dist[v]){        // if it still decreasing
                cout<<"Negative Cycle Exists";
                return;
            }
    }
    for(int i=1; i<=n; i++)
        cout<<1<<"->"<<i<<"="<<dist[i]<<nl;

}
int main() {

    fastio();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});        
    }
    bellmanford(n,edges);
    return 0;
}
/*
Output:
5 5
1 2 1
2 3 5
3 1 -100
4 5 3
3 4 -5
Negative Cycle Exists
*/
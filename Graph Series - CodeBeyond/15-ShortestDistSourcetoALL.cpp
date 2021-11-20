/* Dijkstra's algorithm - find shortest path from source to all vertices in
edge weights can be any positive number - doesn't work for negative cycles
Time Commplexity - O(nlogn + e)*/
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void shortestDistance(int source,int n,vector<pair<int,int>> graph[]){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pQ;  // min heap
    vector<int> dist(n+1,INT_MAX);
    dist[source]=0;
    pQ.push({0,source});            // {dist,node}
    while(!pQ.empty()){
    // node with min weight will always at top in priority queue
        int dis = pQ.top().first;
        int node = pQ.top().second;
        pQ.pop();
        for(auto i:graph[node]){
            int adj = i.first;      // i-> {node,weight}
            int wt = i.second;
            if(dis + wt < dist[adj]){          
                dist[adj] = dis + wt;
                pQ.push({dist[adj],adj});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout<<source<<"->"<<i<<"="<<dist[i]<<nl;

}
int main() {

    fastio();
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[n+1];
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    int source;
    cin>>source;
    shortestDistance(source,n,graph);
    return 0;
}
/*
Output:
5 5
1 2 2
2 3 1
1 3 1
3 4 3
4 5 0
1
1->1=0
1->2=2
1->3=1
1->4=4
1->5=4
*/
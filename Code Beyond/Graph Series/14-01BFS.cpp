/* shortest distance from source to all other nodes
edge weights contains only 0/1
*/
#include<iostream>
#include<deque>
#include<utility>
#include<vector>
#define nl "\n"
#define ll long long
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void BFS01(int source,int n,vector<pair<int,int>> graph[]){
    
    deque<pair<int,int>> dQ;
    vector<int> dist(n+1,INT_MAX);
    dist[source]=0;
    dQ.push_front({source,0});

    while(!dQ.empty()){

        int node = dQ.front().first;
        int dis = dQ.front().second;
        dQ.pop_front();

        for(auto i:graph[node]){
            int adj = i.first;
            int wt = i.second;
            if(dis + wt < dist[adj]){
                dist[adj]=dis+wt;
                if(wt==1)                           
                    dQ.push_back({adj,dis+wt});     // edges with 1 added at back of deque
                else
                    dQ.push_front({adj,dis+wt});    // edges with 0 added at front of deque
            }
            // front of deque always contains minimum weight edge

        }
    }
    for(int i=1;i<=n;i++){
        cout<<source<<"->"<<i<<"="<<dist[i]<<nl;
    }

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
    BFS01(source,n,graph);
    return 0;
}
/*
Output:
5 5
1 2 1
1 3 0
3 4 1
2 4 1
4 5 0
1
1->1=0
1->2=1
1->3=0
1->4=1
1->5=1
*/
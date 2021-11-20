// https://codeforces.com/problemset/problem/20/C
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>
#define int long long
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const long long INF = 1000000000000L;
void shortestPath(int n,vector<pair<int,int>> graph[]){
    
    // we can use set instead of priority queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pQ; // min heap
    vector<int> dist(n+1,INF),parent(n+1,-1);
    parent[1]=1;               // start node is 1
    dist[1]=0;
    pQ.push({0,1});            // {dist,node}
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
                parent[adj] = node;         // update from which node adj came
                pQ.push({dist[adj],adj});
            }
        }
    }

    if(dist[n]==INF){           // path doesn't exist
        cout<<"-1";
        return;
    }
    int x=n;
    vector<int> path;
    path.push_back(x);              // start from last node
    while(parent[x]!=x){            // as parent[1]=1
        x=parent[x];
        path.push_back(x);
    }
    reverse(path.begin(),path.end());   // reverse the path to get from 1 to n
    for(auto i:path)
        cout<<i<<" ";

}
int32_t main() {

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
    shortestPath(n,graph);
    return 0;
}
/*
Output:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
1 4 3 5 
*/
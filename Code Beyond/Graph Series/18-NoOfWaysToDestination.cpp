// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
#include<iostream>
#include<utility>
#include<set>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long  countPaths(long long  n, vector<pair<long long ,long long >> graph[]){

    long long  mod = 1e9 + 7; 
    vector<long long > dist(n,LLONG_MAX),ways(n,0);
    dist[0] = 0;
    ways[0] = 1;                // no of ways to reach 0 with dist 0

    set<pair<long long ,long long >> pQ;          // set works same as priority queue(min heap)
    pQ.insert({0,0});           // dis,node

    while (!pQ.empty()){

        long long  dis = (*pQ.begin()).first;
        long long  node = (*pQ.begin()).second;
        pQ.erase(pQ.begin());

        if(dist[node]<dis)      // if distance less than dis found previously, ignore
            continue;

        for(auto i:graph[node]){

            long long  adj = i.first;
            long long  wt = i.second;
            if(dis + wt < dist[adj]){       // found min distance

                dist[adj] = dis + wt;       // update distance
                ways[adj]  = ways[node];    // ways is no of ways for node
                pQ.insert({dist[adj],adj});
            }
            else if(dis + wt == dist[adj])                  // found same distance
                ways[adj] = (ways[adj] + ways[node])%mod;   // add ways[node]
        }

    }
    return ways[n-1];

}
int main() {

    fastio();
    long long  n,m;
    cin>>n>>m;
    vector<pair<long long ,long long >> graph[n];
    for(long long  i=0;i<m;i++){
        long long  a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    cout<<countPaths(n,graph);

    return 0;
}
/*
Output:
7 10
0 6 7
0 1 2
1 2 3
1 3 3
6 3 3
3 5 1 
6 5 1 
2 5 1
0 4 5
4 6 2
4
*/
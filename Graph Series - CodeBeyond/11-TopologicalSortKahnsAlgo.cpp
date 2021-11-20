#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void topoSortBFS(int n, vector<int> graph[]){

    vector<int> indegree(n+1,0);
    for(auto i=1;i<=n;i++){
        for(auto adj:graph[i]){
            indegree[adj]++;        // i-->adj
        }
    }

    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){         // no incoming edge
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int u = Q.front();
        cout<<u<<" ";
        Q.pop();
        for(auto adj:graph[u]){
            indegree[adj]--;        // remove incomming edge(u)
            if(indegree[adj]==0)
                Q.push(adj);        // if no incomming edges
        }
    }

}
int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    topoSortBFS(n,graph);
    
    return 0;
}
/*
Output:
5 4
1 2
2 3
5 1
4 1
4 5 1 2 3 
*/
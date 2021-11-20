// topological sort
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> courseOrder(int n,vector<int> graph[],vector<int> &indegree){

    int cnt=0;
    queue<int> Q;
    vector<int> ans;
    for(auto i=0;i<n;i++){
        if(indegree[i]==0) {             // nodes with no incomming edges added to queue
            Q.push(i);
            cnt++;
        }
    }
    while(!Q.empty()){
        int u=Q.front();
        ans.push_back(u);
        Q.pop();
        for(auto i:graph[u]){
            indegree[i]--;
            if(indegree[i]==0){          // have no incomming edges
                Q.push(i);
                cnt++;
            }
        }
    }
    bool cycle=false;
    if(cnt!=n)                   // if there's no cycle, exactly n nodes are added to queue
        ans.clear();
    return ans;
}
int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1],indegree(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[b].push_back(a);      // b->a must complete b in order to take a
        indegree[a]++;
    }
    vector<int> ans;
    ans=courseOrder(n,graph,indegree);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}
/*
Output:
3 2
0 1
1 2
2 1 0
*/
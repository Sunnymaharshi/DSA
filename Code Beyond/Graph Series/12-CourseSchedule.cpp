/*
https://leetcode.com/problems/course-schedule/
cycle detection in directed graph or toposort is not possible
*/

#include<iostream>
#include<vector>
using namespace std;
bool hasCycle(int node,vector<int> &vis,vector<int> &pathvis,vector<int> graph[]){

    vis[node]=1;
    pathvis[node]=1;
    for(auto adj:graph[node]){

        if(vis[adj]==0){
            if(hasCycle(adj,vis,pathvis,graph)==true)
                return true;
        }
        else if(vis[adj]==1 && pathvis[adj]==1)
            return true;
    }
    pathvis[node]=0;
    return false;

}
int main() {

    int n,m;
    cin>>n>>m;
    vector<int> graph[n],vis(n,0),pathvis(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[b].push_back(a);          // b->a must complete b in order to take a
    }
    bool cycle = false;
    for(auto i=0;i<n;i++){
            if(vis[i]==0){
               if(hasCycle(i,vis,pathvis,graph)==true){
                    cycle=true;
                    break;
                }                
            }
    }
        
    if(cycle)
        cout<<"Not Possible";
    else
        cout<<"Possible";

    return 0;
}
/*
Output:
2 2
1 0
0 1
Not Possible
*/
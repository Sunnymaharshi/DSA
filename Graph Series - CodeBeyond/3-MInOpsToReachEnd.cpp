/* 
min operations to reach end from start by multiplying given numbers any no of times
we can do this using recursion(DFS)
But BFS is optimal approach
Time Complexity O(end-start+1) since at max u visit all nodes between start and end
*/
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int minOps(int start, int end, vector<int> &vis, vector<int> &arr){

    vis[start]=1; 
    queue<pair<int,int>> Q;
    
    Q.push({start,0});         // node, no of steps 

    while(!Q.empty()){
        int node = Q.front().first;
        int steps = Q.front().second;

        Q.pop();        // remove 1st node
        if(node==end) return steps;

        for(auto i:arr){
            int next = node*i;

            if(next <= end && !vis[next]){  // if next node is valid and steps not calculated before
                Q.push({next,steps+1});     // add it to queue
                vis[next] = 1;              // mark it as visited
            }

        }
    }

    return -1;              // if not possible

}
int main() {

    int start,end,m;
    cin>>start>>end>>m;
    vector<int> arr(m,0);

    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    vector<int> vis(end+1,0);
    cout<<"min operations:"<<minOps(start,end,vis,arr);  

    return 0;
}
/*
Output:
2 20 3
5 1 2
min operations:2
*/
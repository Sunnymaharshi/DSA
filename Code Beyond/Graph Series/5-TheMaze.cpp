// https://www.lintcode.com/problem/787/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
bool canReach(vector<int> &start,vector<int> &end, vector<vector<int>> &maze){

    int n=maze.size();
    int m=maze[0].size();

    queue<pair<int,int>> Q;
    Q.push({start[0],start[1]});

    vector<vector<int>> vis(n,vector<int>(m,0));            // visited matrix
    vis[start[0]][start[1]]=1;          // mark start cell as visited

    while(!Q.empty()){

        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop(); 

        if(x==end[0] && y==end[1])  return true;        // reached end

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int i=0;i<4;i++){
            int newx = x;
            int newy = y;

            while(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]==0){
                newx += dx[i];
                newy += dy[i];
            }
            // we'll cross the boundary of maze or stand on wall
            // go back one step
            newx -= dx[i];
            newy -= dy[i];

            if(vis[newx][newy]==0){             // if it is unvisited
                vis[newx][newy]=1;              // mark it  as visited
                Q.push({newx,newy});            // add that cell to queue
            }
        }
    }
    return false;
}
int main() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin>>mat[i][j];
        }
    }
    vector<int> start(2,0),end(2,0);
    cin>>start[0]>>start[1];
    cin>>end[0]>>end[1];

    if(canReach(start,end,mat)) cout<<"YES";
    else    cout<<"NO";

    return 0;
}
/*
Output:
5 5
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
0 4
4 4
YES
*/
// Dijkstra's algorithm
#include<iostream>
#include<vector>
#include<utility>
#include<set>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &end){

    int n=maze.size();
    int m=maze[0].size();
    vector<int> dist(n*m + 1,INT_MAX);
    // we can represent matrix cells in single digit with (i*m + j)
    dist[start[0]*m + start[1]]=0;          // start cell 

    set<pair<int,pair<int,int>>> pQ;            // set works same as priority queue(min heap)
    pQ.insert({0,{start[0],start[1]}});         // {dist,{i,j}}

    // top,bottom,left,right
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};    

    while (!pQ.empty()){

        int dis = (*pQ.begin()).first;          // {dist,{i,j}}
        int x = (*pQ.begin()).second.first;
        int y = (*pQ.begin()).second.second;
        pQ.erase(pQ.begin());

        for(int ind=0;ind<4;ind++){

            int cnt=0;
            int newx = x;
            int newy = y;
            while(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]==0){
                newx += dx[ind];
                newy += dy[ind];
                cnt++;
            }
            // we cross boundary or stand on wall, so come back one step
            newx -= dx[ind];
            newy -= dy[ind];
            cnt--;

            if(dis + cnt < dist[newx*m + newy]){
                dist[newx*m + newy] = dis + cnt;
                pQ.insert({dis + cnt,{newx,newy}});
            }

        }

    }
    if(dist[end[0]*m + end[1]]==INT_MAX)        // path doesn't exist
        return -1;

    return dist[end[0]*m + end[1]];
}
int main() {

    fastio();
    int n,m,k;
    cin>>n>>m;
    vector<vector<int>> maze(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    vector<int> start,end;
    for(int i=0;i<2;i++){
        cin>>k;
        start.push_back(k);
    }
    for(int i=0;i<2;i++){
        cin>>k;
        end.push_back(k);
    }    

    cout<<shortestDistance(maze,start,end);
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
12
*/
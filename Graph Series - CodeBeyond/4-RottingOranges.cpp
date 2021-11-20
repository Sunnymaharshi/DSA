// https://leetcode.com/problems/rotting-oranges
// multi source bfs
// Time Complexity O(n*m + (n*m - empty cell))
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct  Node {
    int i,j,time;                       // row,col,time
    Node(int i_,int j_, int time_){     
        i=i_;
        j=j_;
        time=time_;
    }
};
int minTime(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();

    queue<Node> Q;
    int cntOranges=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(mat[i][j]==2){           // rotten orange
                Q.push(Node(i,j,0));
            }
            if(mat[i][j]!=0)    cntOranges++; 
        }
    }
    int ans=0,cnt=0;

    while(!Q.empty()){

        int x=Q.front().i;
        int y=Q.front().j;
        int time=Q.front().time;
        ans = time;
        cnt++;                      // count rotten oranges

        Q.pop();                    // remove this rotten orange
        // top right bottom left
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m && mat[newx][newy]==1 ){   
                // if it is inside the matrix and orange is fresh

                mat[newx][newy]=2;              // mark it as rotten
                Q.push(Node(newx,newy,time+1)); // add this to queue and increase it's time
            }            
        }
        
    }

    if(cnt==cntOranges){                        // all oranges are rotten
        return ans;
    }
    return -1;

}
int main() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(m,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    
    cout<<"minimum time to rot all oranges:"<<minTime(mat);
    
    return 0;
}
/*
Output:
3 3
2 1 1 
1 1 0
0 1 1
minimum time to rot all oranges:4
*/
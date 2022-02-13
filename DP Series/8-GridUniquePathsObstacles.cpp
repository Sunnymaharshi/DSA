// Problem Link: https://bit.ly/34uoYCG
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int mod = (int) 1e9+7;

int uniquePathsObs_memo(int row,int col,vector<vector<int>> &maze, vector<vector<int>> &dp){

    if(row>=0 && col>=0 && maze[row][col]==-1)
        return 0;                  // obstacle
    
    if(row==0 && col==0)           // reached top left cell
        return 1;                  // only 1 way to reach (0,0) from (0,0)
    
    if(row<0 || col<0)             
        return 0;                  // reached out of maze

    if(dp[row][col]!=-1)           // already computed
        return dp[row][col];
    

    int up = uniquePathsObs_memo(row-1,col,maze,dp);
    int left = uniquePathsObs_memo(row,col-1,maze,dp);

    return dp[row][col] = (up%mod+left%mod)%mod;    // store ways for cell (r,c)
}

int uniquePathsObs_tabu(int row,int col,vector<vector<int>> &maze){

    int dp[row][col];            
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){

            if(maze[i][j]==-1)          // obstacle
                dp[i][j] = 0;
            else if(i==0 && j==0)       // base case from memo 
                dp[i][j] = 1;           // only 1 way to reach (0,0) from (0,0)
            else{

                int up = 0;
                int left = 0;
                if(i>0)
                    up = dp[i-1][j];    // no of ways for top cell
                if(j>0)
                    left = dp[i][j-1];  // no of ways for left cell

                dp[i][j] = (up%mod+left%mod)%mod;                
            }
        }
    }

    return dp[row-1][col-1];

}
int uniquePathsObs_space_op(int row,int col,vector<vector<int>> &maze){

    // as we are only using just top cell for every row
    // we just store no of ways for previous row for top cell

    vector<int> prev(col,0);            // previous row

    for(int i=0;i<row;i++){

        vector<int> cur(col,0);         // current row

        for(int j=0;j<col;j++){

            if(maze[i][j]==-1)          // obstacle
                cur[j] = 0;
            else if(i==0 && j==0)
                cur[j] = 1;
            else{

                int up = 0;
                int left = 0;
                if(i>0)
                    up = prev[j];
                if(j>0)
                    left = cur[j-1];

                cur[j] = (up%mod+left%mod)%mod;
            }
        }
        prev = cur;                 // make cur row as prev row
    }    

    return prev[col-1];
}
int32_t main() {

    fastio();
    int r,c;
    cin>>r>>c;
    vector<vector<int>> maze(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
        }
    }
    
    // vector<vector<int>> dp(r,vector<int>(c,-1));
    // cout<<uniquePathsObs_memo(r-1,c-1,maze,dp);
    // cout<<uniquePathsObs_tabu(r,c,maze);
    cout<<uniquePathsObs_space_op(r,c,maze);
    return 0;
}
/*
Output:
3 2
3
*/
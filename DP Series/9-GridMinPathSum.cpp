// Problem Link: https://bit.ly/3q5sqfu
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


int minPath_memo(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){

    if(i==0 && j==0)            // reached top left cell
        return grid[i][j];

    if(i<0 || j<0)              // out of grid  
        return (int)1e9;        // return max number to ignore this path

    if(dp[i][j]!=-1)            // already computed for this cell
        return dp[i][j];
    
    // add current cell cost and min cost for top cell
    int up = grid[i][j] + minPath_memo(i-1,j,grid,dp);

    // add current cell cost and min cost for left cell
    int left = grid[i][j] + minPath_memo(i,j-1,grid,dp);
    
    return dp[i][j] = min(up,left);     // store before returning
}

int minPath_tabu(int r,int c, vector<vector<int>> &grid){

    int dp[r][c];
    
    for(int i=0;i<r;i++){

        for(int j=0;j<c;j++){

            if(i==0 && j==0)                // top left cell
                dp[i][j] = grid[i][j];
            else{
                
                int up = (int)1e9;
                int left = (int)1e9;

                if(i>0)                     
                    up = grid[i][j] + dp[i-1][j];   // min cost if we choose top cell in our path
                if(j>0)                     
                    left = grid[i][j] + dp[i][j-1]; // min cost if we choose left cell in our path

                dp[i][j] = min(up,left);           
            }
        }
    }

    return dp[r-1][c-1];
}
int minPath_space_op(int r,int c, vector<vector<int>> &grid){

    // as we are only using just top cell for every row
    // we just store min costs for previous row
    vector<int> prev(c);                    // previous row
    
    for(int i=0;i<r;i++){

        vector<int> cur(c);                 // current row

        for(int j=0;j<c;j++){

            if(i==0 && j==0)                // top left cell
                cur[j] = grid[i][j];
            else{
                
                int up = (int)1e9;
                int left = (int)1e9;

                if(i>0)                        
                    up = grid[i][j] + prev[j];      // min cost if we choose top cell in our path
                if(j>0)
                    left = grid[i][j] + cur[j-1];   // min cost if we choose left cell in our path

                cur[j] = min(up,left); 
            }
        }

        prev = cur;
    }

    return prev[c-1];
}
int32_t main() {
    fastio();

    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c,0));    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>grid[i][j];

    // vector<vector<int>> dp(r,vector<int>(c,-1));
    // cout<<minPath_memo(r-1,c-1,grid,dp);
    // cout<<minPath_tabu(r,c,grid);
    cout<<minPath_space_op(r,c,grid);
    return 0;
}
/*
Output:
2 3
5 9 6
11 5 2
21
*/
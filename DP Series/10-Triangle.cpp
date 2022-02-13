// Problem Link: https://bit.ly/3K1cvqv
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int minPath_memo(int i, int j, int n, vector<vector<int>> &tri,vector<vector<int>> &dp){

    if(i==n-1){                 // reached bottom of the triangle
        return tri[i][j];
    }

    if(dp[i][j]!=-1){           // already completed for this cell
        return dp[i][j];
    }

    int down = tri[i][j] + minPath_memo(i+1,j,n,tri,dp);    // current cell and next row same column
    int diag = tri[i][j] + minPath_memo(i+1,j+1,n,tri,dp);  // current cell and next row next column

    return dp[i][j] = min(down,diag);       // store before returning
}
int minPath_tabu(int n,vector<vector<int>> &tri){

    // start from base case and reach to top of the triangle
    vector<vector<int>> dp(n,vector<int>(n));

    for(int j=0;j<n;j++)                      // base cases as in memoization i.e bottom row
        dp[n-1][j] = tri[n-1][j];
    
    for(int i=n-2;i>=0;i--){                  // 2nd bottom row to top row of triangle

        for(int j=0;j<=i;j++){

            // current cell and next row same column
            int down = tri[i][j] + dp[i+1][j];    
            // current cell and next row next column
            int diag = tri[i][j] + dp[i+1][j+1];  
            
            dp[i][j] = min(down,diag);
        }
    }

    return dp[0][0];
}
int minPath_space_op(int n,vector<vector<int>> &tri){

    // we're just using below row for finding values of current row
    vector<int> below(n),cur(n);

    for(int j=0;j<n;j++)                      // base cases as in memoization i.e bottom row
        below[j] = tri[n-1][j];
    
    for(int i=n-2;i>=0;i--){                  // 2nd bottom row to top row of triangle

        
        for(int j=0;j<=i;j++){

            // current cell and next row same column
            int down = tri[i][j] + below[j];    
            // current cell and next row next column
            int diag = tri[i][j] + below[j+1];  
            
            cur[j] = min(down,diag);
        }

        below = cur;        // make current row as below row
    }

    return below[0];
}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<vector<int>> triangle;
    for(int i=1;i<=n;i++){
        vector<int> row;
        for(int j=1;j<=i;j++){
            int t;
            cin>>t;
            row.push_back(t);
        }
        triangle.push_back(row);
    }

    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // // In memo start from top and go all possible paths to bottom of triangle
    // cout<<minPath_memo(0,0,n,triangle,dp);  
    // cout<<minPath_tabu(n,triangle);
    cout<<minPath_space_op(n,triangle);  

    return 0;
}
/*
Output:
*/
// Problem Link: https://bit.ly/3F436d
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    fix an ending cell, find max path sum from cell in top row to this ending cell.
    do this for all ending cells, take max of these paths.
*/
int maxPath_memo(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){

    if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size())      // out of boundary of matrix
        return (int) -1e9;                  // return big negative value to ignore this path

    if(i==0)                                // reached top row of matrix
        return mat[i][j];
    
    if(dp[i][j]!=-1)                        // already computed for this cell
        return dp[i][j];
    int top = mat[i][j] + maxPath_memo(i-1,j,mat,dp);               // top cell in upper row
    int ldiag = mat[i][j] + maxPath_memo(i-1,j-1,mat,dp);           // left diagonal cell in upper row
    int rdiag = mat[i][j] + maxPath_memo(i-1,j+1,mat,dp);           // right diagonal cell in upper row

    return dp[i][j] = max(top,max(ldiag,rdiag));      // store before return max of all possible paths    
}

int maxPath_tabu(int n,int m,vector<vector<int>> &mat){

    int maxsum = (int) -1e9;
    vector<vector<int>> dp(n,vector<int>(m));

    for(int j=0;j<m;j++)                 // base cases in memoization
        dp[0][j] = mat[0][j];               
    
    for(int i=1;i<n;i++){                // from 2nd to last row

        for(int j=0;j<m;j++){            // for every column

            int top = mat[i][j] + dp[i-1][j];       // top cell in upper row

            int ldiag,rdiag;         // for out of boundary cases, initialize with big negative value
            ldiag = (int) -1e9;
            rdiag = (int) -1e9;
            if(j-1>=0)
                ldiag = mat[i][j] + dp[i-1][j-1];   // left diagonal cell in upper row
            if(j+1<m)
                rdiag = mat[i][j] + dp[i-1][j+1];   // right diagonal cell in upper row

            dp[i][j] = max(top,max(ldiag,rdiag));
        }
    }

    for(int j=0;j<m;j++)                            // max of path sums of all ending cells 
        maxsum = max(maxsum,dp[n-1][j]);
    
    return maxsum;
}
int maxPath_space_op(int n,int m,vector<vector<int>> &mat){

    // we're just using upper row values to find values of current row

    int maxsum = (int) -1e9;
    vector<int> upper(m),cur(m);        // upper and current rows

    for(int j=0;j<m;j++)                // base cases in memoization
        upper[j] = mat[0][j];               
    
    for(int i=1;i<n;i++){               

        for(int j=0;j<m;j++){           

            int top = mat[i][j] + upper[j];       // top cell in upper row

            int ldiag,rdiag;         // for out of boundary cases, initialize with big negative value
            ldiag = (int) -1e9;
            rdiag = (int) -1e9;
            if(j-1>=0)
                ldiag = mat[i][j] + upper[j-1];   // left diagonal cell in upper row
            if(j+1<m)
                rdiag = mat[i][j] + upper[j+1];   // right diagonal cell in upper row

            cur[j] = max(top,max(ldiag,rdiag));
        }

        upper = cur;              // make current row as upper
    }

    for(int j=0;j<m;j++)                 // max of max path sums of all ending cells 
        maxsum = max(maxsum,upper[j]);
    
    return maxsum;
}
int32_t main() {
    fastio();

    int n,m,maxsum;
    cin>>n>>m;
    maxsum = (int) -1e9;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];

    // vector<vector<int>> dp(n,vector<int>(m,-1));
    
    // for(int j=0;j<m;j++){  

    //     // find max path sum from every cell in last row to any cell in first row.
    //     // take max of these paths.
    //     maxsum = max(maxsum,maxPath_memo(n-1,j,mat,dp));
    // } 
    // cout<<maxsum;

    // cout<<maxPath_tabu(n,m,mat);
    cout<<maxPath_space_op(n,m,mat);

    return 0;   
}
/*
Output:
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
105
*/
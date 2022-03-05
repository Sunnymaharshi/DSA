// Problem Link: https://bit.ly/3pvkqUd
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int lcs_memo(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp){

    // any of both strings completed, then there is no common subsequence exists
    if(i1<0 || i2<0)
        return 0;

    // both indexes have same character, we can include that character in our lcs
    // reduce the indexes to check remaining strings
    if(s1[i1]==s2[i2])
        return dp[i1][i2] = 1 + lcs_memo(i1-1,i2-1,s1,s2,dp);    

    if(dp[i1][i2]!=-1)
        return dp[i1][i2];      

    /*  
        both characters doesn't match 
        we may find common for either of both characters or both characters or none
        we skip characters to check all possible subsequences.
        lcs can be found by skiping character either in 1st or 2nd string
        we check both and take max of them
    */

    // skip current character in 1st string and check remaining strings
    // skip current character in 2nd string and check remaining strings
    return dp[i1][i2] = max(lcs_memo(i1-1,i2,s1,s2,dp),lcs_memo(i1,i2-1,s1,s2,dp));    
}

int lcs_tabu(string s1,string s2){

    /*
        As base case in memoization has negative value check i.e -1
        dp array cannot contain negative indexes
        so we shift all index to right, i.e -1 will be 0, 0 will be 1
        so on n-1,m-1, will be n,m.
        while checking strings we reduce these indexes.
    */
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    // Base cases in memoization
    /*
        for any index of 1st string, if 2nd string is completed
        i2<0 in memoization is written in index 0 as we shifted indexes
    */
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    /*
        for any index of 2nd string, if 1st string is completed
        i1<0 in memoization is written in index 0 as we shifted indexes
    */
    for(int j=0;j<=m;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // reduce indexes while checking as we've shifted them to store base
            // cases in dp array
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    // lcs for s1(0 to n-1) and s2(0 to m-1)
    return dp[n][m];
}

int lcs_space_op(string s1,string s2){

    int n=s1.size(),m=s2.size();
    // In tabulation, we're just using previous index values of 1st string
    // cur and prev index values of 1st string
    vector<int> prev(m+1,0),cur(m+1,0);

    // i1<0 base case in memoization
    for(int j=0;j<=m;j++)
        prev[j] = 0;
    
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // reduce indexes while checking as we've shifted them to store base
            // cases in dp array
            if(s1[i-1]==s2[j-1])
                cur[j] = 1 + prev[j-1];
            else
                cur[j] = max(prev[j],cur[j-1]);
        }

        prev = cur;         // make cur index values of 1st string as previous
    }

    return prev[m];
}

int32_t main() {
    fastio();

    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<lcs_memo(n-1,m-1,s1,s2,dp);
    // cout<<lcs_tabu(s1,s2);
    cout<<lcs_space_op(s1,s2);
    return 0;
}
/*
Output:
adebc
dcadb
3
*/
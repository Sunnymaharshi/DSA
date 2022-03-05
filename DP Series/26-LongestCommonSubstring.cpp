// Problem Link: https://bit.ly/3H2M3KS
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int LCSubstring_tabu(string s1,string s2){

    
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
    
    int ans = 0;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // reduce indexes while checking as we've shifted them to store base
            // cases in dp array
            if(s1[i-1]==s2[j-1]){
                // if both characters match, add 1 for current match
                // and add value of next previous indexes of both string
                dp[i][j] = 1 + dp[i-1][j-1];

                // LCSubstring can be anywhere
                ans = max(ans,dp[i][j]);
            }
            else{
                // since we want substring, we can't skip characters.
                dp[i][j] = 0;
            }            
        }
    }       
    return ans;
}
int LCSubstring_space_op(string s1,string s2){

    
    int n=s1.size(),m=s2.size();

    // In tabulation, we're just using previous index values of 1st string
    vector<int> prev(m+1,0),cur(m+1,0);
    // Base cases in memoization
    for(int j=0;j<=m;j++)
        prev[j] = 0;
    
    int ans = 0;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // reduce indexes while checking as we've shifted them to store base
            // cases in dp array
            if(s1[i-1]==s2[j-1]){
                // if both characters match, add 1 for current match
                // and add value of next previous indexes of both string
                cur[j] = 1 + prev[j-1];

                // LCSubstring can be anywhere
                ans = max(ans,cur[j]);
            }
            else{
                // since we want substring, we can't skip characters.
                cur[j] = 0;
            }            
        }

        prev = cur;      // make cur index values of 1st string as previous
    }       
    return ans;
}
int32_t main() {
    fastio();

    string s1,s2;
    cin>>s1>>s2;
    // cout<<LCSubstring_tabu(s1,s2);
    cout<<LCSubstring_space_op(s1,s2);

    return 0;
}
/*
Output:
tyfg cvbnuty
2
*/
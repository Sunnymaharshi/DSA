// Problem Link: https://bit.ly/3H2ZtGP
#include<iostream>
#include<vector>
#include<algorithm>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/*
    We'll keep longest palindromic subsequence as it is,
    other letters are inserted at opposite side to make string palindrome.
    total len - length of longest palindromic subsequence = min no of insertions
    to make string palindrome.
    Longest common subsequence between given string and reverse of given 
    string gives longest palindromic subsequence
*/
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
int32_t main() {
    fastio();

    string s,r;
    cin>>s;
    r=s;
    int n = s.size(), lps;
    reverse(r.begin(),r.end());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    lps = lcs_memo(n-1,n-1,s,r,dp);

    cout<<n-lps;

    return 0;
}
/*
Output:
helper
3
*/
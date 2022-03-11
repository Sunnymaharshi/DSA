#include<iostream>
#include<vector>
#include<algorithm>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/*
    string that has both given strings as it's subsequences
    is called common supersequence.
    we keep common subsequence in both as it is and add remaining.

    we only add lcs at once and add remaining in same order.
    len of shortest common supersequence = n+m - lcs_len.
*/
string SCSupersequence(string str1,string str2){

    int n=str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    // LCS tabulation
    /*
        for any index of 1st string, if 2nd string is completed
        i2<0 in memoization is written in index 0 as we shifted indexes
    */
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    /*
        for any index of 2nd string, if 1st string is completed
        i1<0 in memoization is wri tten in index 0 as we shifted indexes
    */
    for(int j=0;j<=m;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            // reduce indexes while checking as we've shifted them to store base
            // cases in dp array
            if(str1[i-1]==str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    
    int SCS_len = n+m - dp[n][m];                 // len of SCS
    int i=n,j=m;
    string SCS = "";

    while (i>0 && j>0)
    {
        if(str1[i-1]==str2[j-1]){
            // letter in LCS, add only once
            SCS += str1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            // letter in str1 not in LCS, add it
            SCS += str1[i-1];
            i--;
        }
        else{
            // letter in str2 not in LCS, add it
            SCS += str2[j-1];
            j--;
        }
    }

    // left out letters in str1
    while (i>0)
    {
        SCS += str1[i-1];
        i--;
    }
    // left out letters in str2
    while (j>0)
    {
        SCS += str2[j-1];
        j--;
    }

    // as we are adding letters from right, reverse SCS
    reverse(SCS.begin(),SCS.end());

    return SCS;   
}
int32_t main() {
    fastio();

    string a,b;
    cin>>a>>b;
    cout<<SCSupersequence(a,b);
    
    return 0;
}
/*
Output:
brute
groot
bgruoote
*/
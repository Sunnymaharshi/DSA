#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


string lcsPrint_tabu(string s1,string s2){

    // tabulation used to find lcs length
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

    
    int len = dp[n][m];                 // len of lcs

    string ans = "";
    // insert dummy character to lcs string
    for(int i=0;i<len;i++)
        ans += "d";

    int ind = len-1;            // we fill lcs from last index
    int i=n,j=m;
    while(i>0 && j>0){

        if(s1[i-1]==s2[j-1]){       // if both indexes match, add character to ans

            ans[ind] = s1[i-1];
            ind--;
            // as we've found the match, reduce both indexes
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            // lcs is found by skiping character from 1st string
            i--;        
        }
        else{
            // lcs is found by skiping character from 2nd string
            j--;
        }   
    }

    return ans;
}
int32_t main() {
    fastio();

    int len;
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    cout<<lcsPrint_tabu(s1,s2);
    return 0;
}
/*
Output:
adebc
dcadb
adb
*/
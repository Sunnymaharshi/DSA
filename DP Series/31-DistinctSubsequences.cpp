#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int distinctSubsequences_memo(int i,int j,string &s,string &t,vector<vector<int>> &dp){

    // matched all characters of target string
    if(j<0)
        return 1;
    
    // traversed all characters from string s
    // still some characters are pending from target string
    if(i<0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(s[i]==t[j]){
        /*
            characters matching, we find match for remaining characters.
            since there exists multiple subsequence 
            we might find same matching character again,
            may find another matching subsequnce.
            try to find another matching for this string t without taking 
            current matching character into our subsequence.
        */
       // pick this character, match remaining target string
       int pick = distinctSubsequences_memo(i-1,j-1,s,t,dp);

       // do not pick this character, match target string
       int notPick = distinctSubsequences_memo(i-1,j,s,t,dp);

       return dp[i][j] = pick + notPick;
    }
    // characters not matching, we can't take this character into our subsequence
    else
        return dp[i][j] = distinctSubsequences_memo(i-1,j,s,t,dp);    
}

int distinctSubsequences_tabu(string &s,string &t){

    int n=s.size(),m=t.size();
    vector<vector<double>> dp(n+1,vector<double>(m+1,0));

    // Base cases in memoization
    /*  
        we've negative check i.e i<0 and j<0
        as we can't have negative index in the dp array
        we shift index by 1 to right i.e 0 for -1, 1 for 0
        so on m for m-1 n for n-1.
        we reduce values when checking strings.
    */
    // for any i, if target string is matched completely
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    // string s is completed but target is not completed
    // dp is already initialized with 0, so no need of this base case
    // for(int j=1;j<=m;j++)
    //     dp[0][j] = 0;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){
            // as we shifted indexes to right, reduce while checking
            if(s[i-1]==t[j-1]){
                
                double notPick = dp[i-1][j];
                double pick = dp[i-1][j-1];
                dp[i][j] = notPick + pick;
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return (int) dp[n][m];
}

int distinctSubsequences_space_op1(string &s,string &t){

    int n=s.size(),m=t.size();
    vector<double> prev(m+1,0),cur(m+1,0);
    /*
        In tabulation, we're just using dp[i-1] values to
        find current dp[i] values.
    */

    prev[0] = cur[0] = 1;            // j<0 base case

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){
            // as we shifted indexes to right, reduce while checking
            if(s[i-1]==t[j-1]){
                
                double notPick = prev[j];
                double pick = prev[j-1];
                cur[j] = notPick + pick;
            }
            else
                cur[j] = prev[j];
        }

        prev = cur;             // make current i values as prev
    }

    return (int)prev[m];
}
int distinctSubsequences_space_op2(string &s,string &t){

    int n=s.size(),m=t.size();
    vector<double> prev(m+1,0);
    /*
        In space op1, we're just using left indexes(j-1) value of prev to
        find current index(j) values of cur.
        if we calculate values from m to 1, we take (j-1) value
        and update j value with single array.
        right side of j act as cur array.
        left side of j act as prev array.
        we fill array from right to left.
    */

    prev[0] = 1;            // j<0 base case

    for(int i=1;i<=n;i++){

        for(int j=m;j>=1;j--){
            // as we shifted indexes to right, reduce while checking
            if(s[i-1]==t[j-1]){
                
                double notPick = prev[j];
                double pick = prev[j-1];
                prev[j] = notPick + pick;
            }
            //  no need to copy same value again.
            /* else
                   prev[j] = prev[j];
            */
        }
    }

    return (int)prev[m];
}
int32_t main() {
    fastio();

    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<distinctSubsequences_memo(n-1,m-1,s,t,dp);
    // cout<<distinctSubsequences_tabu(s,t);
    // cout<<distinctSubsequences_space_op1(s,t);
    cout<<distinctSubsequences_space_op2(s,t);

    return 0;
}
/*
Output:
rabbbit
rabbit
3
*/
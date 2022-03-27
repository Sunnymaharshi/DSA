#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool wildcardMatch_memo(int i,int j,string &p,string &s,vector<vector<int>> &dp){

    // pattern is matched with string completely
    if(i<0 && j<0)
        return true;
    
    // pattern is completed, but string has some unmatched characters
    if(i<0 && j>=0)
        return false;

    // pattern is not completed,but string is matched completely
    if(i>=0 && j<0){

        // if all the remaining characters in pattern are *
        // we can use all those *'s for matching 0 characters of string
        // and complete the pattern
        for(int ind=0;ind<=i;ind++){

            // there is an unmatched character in pattern
            // if character is ? then also we return false
            // as we don't have characters left in string to match with '?'
            if(p[ind]!='*')
                return false;
        }
        // all the remaining characters in pattern are *'s 
        // we use 0 character matching for those *'s and complete the pattern
        return true;
    }

    if(dp[i][j]!=-1)
        return dp[i][j];

    // character is matched or ? to match exactly one character
    if(p[i]==s[j] || p[i]=='?')
        return dp[i][j] = wildcardMatch_memo(i-1,j-1,p,s,dp);

    if(p[i]=='*'){
        // 1. don't match and move to next character in pattern
        //2. match 1 character move to next character in string
        // stay on same index of pattern, as we can match
        // any no of characters using *
        return dp[i][j] = wildcardMatch_memo(i-1,j,p,s,dp) |
         wildcardMatch_memo(i,j-1,p,s,dp);
    }

    // both are alphabets and not matching
    return dp[i][j] = false;
}

bool wildcardMatch_tabu(string p,string s){

    int n=p.size(),m=s.size();

    // Base cases in memoization
	/* 
		we've negative check i.e i<0 and j<0
		as we can't have negative index in the dp array
		we shift index by 1 to right i.e 0 for -1, 1 for 0
		so on m for m-1 n for n-1.
		we reduce values when checking string and pattern.
	*/
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    // i<0 and j<0 
    dp[0][0] = true;
    // i<0 and j>=0
    for(int j=1;j<=m;j++)
        dp[0][j] = false;
    // i>=0 and j<0
    for(int i=1;i<=n;i++){

        dp[i][0] = true;
        for(int ind=1;ind<=i;ind++){

            if(p[ind-1]!='*'){

                dp[i][0] = false;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){
            
            // reduce indexes while checking string and pattern 
            // as we've shifted indexes to right
            if(p[i-1]==s[j-1] || p[i-1]=='?'){

                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[i-1]=='*'){

                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

bool wildcardMatch_space_op(string p,string s){

    // In tabulation, we're just using dp[i-1] values
    // to find dp[i] values
    int n=p.size(),m=s.size();
    // previous and current index values of pattern
    vector<bool> prev(m+1,false), cur(m+1,false);

    // i<0 and j<0 
    prev[0] = true;
    // i<0 and j>=0
    for(int j=1;j<=m;j++)
        prev[j] = false;
    
    for(int i=1;i<=n;i++){

        // i>=0 and j<0, for every index of pattern
        cur[0] = true;
        for(int ind=1;ind<=i;ind++){

            if(p[ind-1]!='*'){

                cur[0] = false;
                break;
            }
        } 

        for(int j=1;j<=m;j++){

            // reduce indexes while checking string and pattern 
            // as we've shifted indexes to right
            if(p[i-1]==s[j-1] || p[i-1]=='?'){

                cur[j] = prev[j-1];
            }
            else if(p[i-1]=='*'){

                cur[j] = prev[j] | cur[j-1];
            }
            else
                cur[j] = false;
        }

        // make current index values of pattern as previous index values
        prev = cur;
    }

    return prev[m];

}
int32_t main() {
    fastio();

    string s,p;
    cin>>s>>p;
    int n=p.size(),m=s.size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<wildcardMatch_memo(n-1,m-1,p,s,dp);
    // cout<<wildcardMatch_tabu(p,s);
    cout<<wildcardMatch_space_op(p,s);
    return 0;
}
/*
Output:
aa
*
1
*/
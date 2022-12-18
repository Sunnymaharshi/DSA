// Problem Link: https://bit.ly/32tAMUW
// total no of ways to evaluate a boolean expression to true
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define ll long long
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int mod = 1000000007;

// no of ways u can evaluate expression to isTrue(what u r looking for)
ll noOfWays(int i,int j, int isTrue, string &exp,vector<vector<vector<ll>>> &dp){

    // end of expression
    if(i>j) return 0;
    
    // only single value is present
    if(i==j){

        // if value is isTrue, then it is 1 way
        if(isTrue) return exp[i]=='T';
        
        else return exp[i]=='F';
    }

    // if already calculated
    if(dp[i][j][isTrue]!=-1) 
        return dp[i][j][isTrue];

    ll ways = 0;
    
    // partition at all boolean operators
    for(int ind=i+1; ind<=j-1; ind+=2){

        // no of ways for left expression
        ll leftTrue = noOfWays(i,ind-1,1,exp,dp);
        ll leftFalse = noOfWays(i,ind-1,0,exp,dp);

        // no of ways for right expression
        ll rightTrue = noOfWays(ind+1,j,1,exp,dp);
        ll rightFalse = noOfWays(ind+1,j,0,exp,dp);

        if(exp[ind]=='&'){
            
            if(isTrue)
                ways = (ways + (leftTrue*rightTrue) % mod) % mod;
            else
                ways = (ways + 
                            (leftTrue*rightFalse) % mod + 
                            (leftFalse*rightTrue) % mod + 
                            (leftFalse*rightFalse) % mod
                        ) % mod;
        }

        else if(exp[ind]=='|'){
            
            if(isTrue)
                ways = (ways + 
                            (leftTrue*rightTrue) % mod + 
                            (leftTrue*rightFalse) % mod + 
                            (leftFalse*rightTrue) % mod
                        ) % mod;
            else
                ways = (ways + (leftFalse*rightFalse) % mod) % mod;
        }

        else if(exp[ind]=='^'){

            if(isTrue)
                ways = (ways + 
                            (leftTrue*rightFalse) % mod + 
                            (leftFalse*rightTrue) % mod
                        ) % mod;
            else
                ways = (ways + 
                            (leftTrue*rightTrue) % mod + 
                            (leftFalse*rightFalse) % mod
                        ) % mod;
        }
        
    }

    return dp[i][j][isTrue] = ways;
}


int main() {
    fastio();

    string exp;
    cin>>exp;

    int n = exp.size();
    // changing parameters range, matrix size n X n X 2
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    cout<< noOfWays(0,n-1,1,exp,dp);
    return 0;    
}

/*
Output:
*/
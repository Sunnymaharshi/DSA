#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/* 
memoization in overlaping sub problems - Top Down

                f(4)
            f(3)     f(2)-> here no need to compute f(2) again, 
        f(2)    f(1)        f(2) is previously computed and store in dp
    f(1)    f(0)            just return dp[2]

Time Complexity - O(N)  fibo for every number 2 to n Computes only once
Space Complexity - O(N+N) one for stack space and other for dp array
*/
int fibo_memo(int n,vector<int> &dp){

    if(n<=1){
        return n;
    }

    if(dp[n]!=-1){                  // fibo(n) already computed before
        return dp[n];       
    }

    // store fibo(n) before returning
    return dp[n] = fibo_memo(n-1,dp)+fibo_memo(n-2,dp); 

}
/*
tabulation - Bottom up
Time Complexity - O(N)
Space Complexity - O(N) for dp array
*/
int fibo_tab(int n){

    vector<int> dp(n+1);
    // base cases in recursion
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        // similar to what we compute in recursion
        // we just build our ans from base case to n
        dp[i] = dp[i-1] + dp[i-2];          
    }
    return dp[n];
}
/* 
Space Optimization
Time Complexity - O(N)
Space Complexity - O(1)
*/
int fibo_tab_op(int n){

    // all we need is dp[n-1] and dp[n-2] values to compute dp[n]
    int cur, prev2 = 0, prev = 1;
    for(int i=2;i<=n;i++){

        cur = prev + prev2;         // find fibo of i
        prev2 = prev;               // move variables ahead
        prev = cur;
    }
    /*
    even if prev and cur store same value after an iteration
    if n=1, for loop never executes, we can't return cur which is never initialized
    hence with prev we can cover this edge case
    */
    return prev;

}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<<fibo_memo(n,dp);
    // cout<<fibo_tab(n);
    cout<<fibo_tab_op(n);
    return 0;
}
/*
Output:
10
55
*/
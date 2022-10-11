// Problem Link: https://bit.ly/3nXqfce
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/*
    Matrices A(10x30) B(30x5) C(5x60)

    A*B*C = A*(B*C) = (A*B)*C

    A*(B*C) = (10x30) * ((30x5)*(5x60))     30*5*60 = 9000ops
            = (10x30) * (30x60)             10*30*60 = 18000ops
            = (10x60)                  
    total = 27,000 multiplication operations

    (A*B)*C = ((10x30)*(30x5)) * (5x60)     10*30*5 = 1500ops
            = (10x5) * (5x60)               10*5*60 = 3000ops
            = (10x60)
    total = 4,500 multiplication operations
    this way gives same answer with very less operations.
*/

/*
    Recursion tree:

                        ABCD

            A*(BCD)     (AB)*(CD)       (ABC)*D

      B*(CD)      (BC)*D

    C        D

    tries all partitions in every part until it reaches to single matrix
*/
int minOperations_memo(int i, int j, vector<int> &arr,vector<vector<int>> &dp){

    if(i==j)               // single matrix, 0 multiplication operations
        return 0;

    if(dp[i][j]!=-1)        // already computed for this block
        return dp[i][j];    

    int min_ops = 1e9;

    // partition in every possible position and take min ops.
    for(int p=i;p<j;p++){

        // operations required to multiply these two parts of this partition
        int ops = arr[i-1] * arr[p] * arr[j]; 

        // operations required for each part
        ops += minOperations_memo(i,p,arr,dp) + minOperations_memo(p+1,j,arr,dp);

        min_ops = min(min_ops,ops);
    }

    return dp[i][j] = min_ops;
}

int minOperations_tabu(int n,vector<int> &arr){

    vector<vector<int>> dp(n,vector<int>(n,0));

    // Base case
    for(int i=0;i<n;i++)
        dp[i][i] = 0;
    
    // In memoization, we started i from 1, here we go reverse
    // i.e n-1 to 1
    for(int i=n-1;i>=1;i--){

        // partition always happens between i and j
        // j can't be less than i, so we take j from i+1
        for(int j=i+1;j<n;j++){

            int min_ops = 1e9;

            for(int p=i;p<j;p++){
                
                // operations for two parts of this partition
                int ops = arr[i-1] * arr[p] * arr[j]; 

                ops += dp[i][p] + dp[p+1][j];

                min_ops = min(min_ops,ops);
            }

            dp[i][j] = min_ops;
        }
    }

    return dp[1][n-1];
}

int32_t main() {
    fastio();

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // cout<<minOperations_memo(1,n-1,arr,dp);
    cout<<minOperations_tabu(n,arr);
    return 0;
}
/*
Output:
4
1 4 3 2
18
*/
// Problem Link: https://bit.ly/3Kgck9N
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// we can't solve it as individual problems, so use bottom up approach ??
int maxCost_memo(int i, int j, vector<int> &arr, vector<vector<int>> &dp){

    if(i>j) return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int max_cost = INT32_MIN;

    for(int ind=i; ind<=j; ind++){

        int cost = arr[i-1] * arr[ind] * arr[j+1];        
        cost += maxCost_memo(i,ind-1,arr,dp) + maxCost_memo(ind+1,j,arr,dp);  // add cost for remaining sides
        max_cost = max(max_cost,cost);
    }

    return dp[i][j] = max_cost;
}

int maxCost_tabu(vector<int> arr,int n){

    vector<vector<int>> dp(n+2,vector<int>(n+2,0));

    // base case covers as we initialised array with 0s

    for(int i=n; i>=1; i--){

        for(int j=1; j<=n; j++){

            if(i>j) continue;

            int max_cost = INT32_MIN;    

            for(int ind=i; ind<=j; ind++){

                int cost = arr[i-1] * arr[ind] * arr[j+1];                
                cost += dp[i][ind-1] + dp[ind+1][j];        // add cost for remaining sides
                max_cost = max(max_cost,cost);
            }

            dp[i][j] = max_cost;
        }
    }

    return dp[1][n];
}
int main() {
    fastio();

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // to ease the cost finding add 1s at both ends
    arr.push_back(1);
    arr.insert(arr.begin(),1);

    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // 1 as we've added 1's at both ends
    // cout<<maxCost_memo(1,n,arr,dp);

    cout<<maxCost_tabu(arr,n);
}

/*
Output:
3
7 1 8
120
*/
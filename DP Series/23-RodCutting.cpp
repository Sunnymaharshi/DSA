// Problem Link: https://bit.ly/3H10kYJ
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int maxPrice_memo(int i,int tar_len,vector<int> &prices,vector<vector<int>> &dp){

    if(i==0){               // final size, cutting rod with size 1

        // as it is final size we can cut rod multiple times at once
        return tar_len*prices[0];  
    }
    
    if(dp[i][tar_len]!=-1)
        return dp[i][tar_len];

    int notTake = maxPrice_memo(i-1,tar_len,prices,dp);
    int take = INT_MIN;
    int cut_size = i+1;
    if(cut_size<=tar_len){
        // add price for cut size and reduce target rod len
        // stay on same cut size as we can cut same size any no of times
        take = prices[i] + maxPrice_memo(i,tar_len-cut_size,prices,dp);
    }

    return dp[i][tar_len] = max(take,notTake);
}

int maxPrice_tabu(int n, vector<int> &prices){

    vector<vector<int>> dp(n,vector<int>(n+1,0));

    // base case in memoization
    for(int tar_len=0;tar_len<=n;tar_len++){

        dp[0][tar_len] = tar_len*prices[0];         // cut_size = 0+1 =1
    }

    for(int i=1;i<n;i++){                       // for all cut sizes

        for(int tar_len=0;tar_len<=n;tar_len++){        // for all target lengths

            int notTake = dp[i-1][tar_len];
            int take = INT_MIN;
            int cut_size = i+1;
            if(cut_size<=tar_len){
                // add price for cut size and reduce target rod len
                // stay on same cut size as we can cut same size any no of times
                take = prices[i] + dp[i][tar_len-cut_size];
            }

            dp[i][tar_len] = max(take,notTake);
        }
    }

    // max price for rod len n, considering all cut sizes 1 to n
    return dp[n-1][n];
}

int maxPrice_space_op1(int n, vector<int> &prices){

    // In tabulation, we're just using previous cut_size values
    // to find current cut_size values
    vector<int> prev(n+1,0),cur(n+1,0);

    // base case in memoization
    for(int tar_len=0;tar_len<=n;tar_len++){

        prev[tar_len] = tar_len*prices[0];         // cut_size = 0+1 =1
    }

    for(int i=1;i<n;i++){                       // for all cut sizes

        for(int tar_len=0;tar_len<=n;tar_len++){        // for all target lengths

            int notTake = prev[tar_len];
            int take = INT_MIN;
            int cut_size = i+1;
            if(cut_size<=tar_len){
                // add price for cut size and reduce target rod len
                // stay on same cut size as we can cut same size any no of times
                take = prices[i] + cur[tar_len-cut_size];
            }

            cur[tar_len] = max(take,notTake);
        }

        prev = cur;             // make current cut_size values as previous
    }

    return prev[n];
}

int maxPrice_space_op2(int n, vector<int> &prices){

    /*
        we're just using current index value in prev array
        and index<=tar_len value in cur array.
        so we only using tar_len value from prev array

        we can use single array, tar_len acts as prev array
        and we can update indexes less than tar_len.
    */
    vector<int> prev(n+1,0);

    // base case in memoization
    for(int tar_len=0;tar_len<=n;tar_len++){

        prev[tar_len] = tar_len*prices[0];         // cut_size = 0+1 =1
    }

    for(int i=1;i<n;i++){                       // for all cut sizes

        for(int tar_len=0;tar_len<=n;tar_len++){        // for all target lengths

            int notTake = prev[tar_len];
            int take = INT_MIN;
            int cut_size = i+1;
            if(cut_size<=tar_len){
                // add price for cut size and reduce target rod len
                // stay on same cut size as we can cut same size any no of times
                take = prices[i] + prev[tar_len-cut_size];
            }

            prev[tar_len] = max(take,notTake);
        }
    }

    return prev[n];
}


int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    // n for 1st dimension,i+1 represents cut size
    // n+1 for 2nd dimension, as we need to get target len n
    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // cout<<maxPrice_memo(n-1,n,prices,dp);
    // cout<<maxPrice_tabu(n,prices);
    // cout<<maxPrice_space_op1(n,prices);
    cout<<maxPrice_space_op2(n,prices);
    return 0;
}
/*
Output:
*/
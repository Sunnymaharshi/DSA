// Problem Link: https://bit.ly/3IvPdXS
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int maxValue_memo(int i,int bag_wt,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){

    if(i==0){               // reached final item
        // as it is final item we can take multiple items at once
        return ((int)(bag_wt/wt[0])) * val[0];
    }

    if(dp[i][bag_wt]!=-1)               // already computed
        return dp[i][bag_wt];
    
    int notTake = maxValue_memo(i-1,bag_wt,wt,val,dp);        // move to next item
    int  take = 0;
    if(wt[i]<=bag_wt){
        // add it's value, reduce the bag weight and stay on same item
        // as we can take items any no of items
        take = val[i] + maxValue_memo(i,bag_wt-wt[i],wt,val,dp);
    }

    return dp[i][bag_wt] = max(take,notTake);
}


int maxValue_tabu(int n,int bag_wt,vector<int> &wt,vector<int> &val){

    vector<vector<int>> dp(n,vector<int>(bag_wt+1,0));
    // base case in memoization
    for(int bw=0;bw<=bag_wt;bw++){

        dp[0][bw] = ((int)bw/wt[0]) * val[0];
    }

    for(int i=1;i<n;i++){

        for(int bw=0;bw<=bag_wt;bw++){

            int notTake = dp[i-1][bw];        
            int  take = 0;
            if(wt[i]<=bw){
                // add it's value, reduce the bag weight and stay on same item
                // as we can take items any no of items
                take = val[i] + dp[i][bw-wt[i]];
            }

            dp[i][bw] = max(take,notTake);
        }
    }
    // max value with bag weight as bag_wt, considering 0-(n-1)th index items
    return dp[n-1][bag_wt];
}

int maxValue_space_op1(int n,int bag_wt,vector<int> &wt,vector<int> &val){

    // In tabulation we're just using previous item values to find values
    // of current item
    vector<int> prev(bag_wt+1,0),cur(bag_wt+1,0);

    // base case in memoization
    for(int bw=0;bw<=bag_wt;bw++){

        prev[bw] = ((int)bw/wt[0]) * val[0];
    }

    for(int i=1;i<n;i++){

        for(int bw=0;bw<=bag_wt;bw++){

            int notTake = prev[bw];        
            int  take = 0;
            if(wt[i]<=bw){
                // add it's value, reduce the bag weight and stay on same item
                // as we can take items any no of items
                take = val[i] + cur[bw-wt[i]];
            }

            cur[bw] = max(take,notTake);
        }

        prev = cur;             // make current item as previous item
    }

    return prev[bag_wt];
}

int maxValue_space_op2(int n,int bag_wt,vector<int> &wt,vector<int> &val){
    
    /*  
        int notTake = prev[bw];
        for notTake, we are using same value as in prev

        take = val[i] + cur[bw-wt[i]];
        for take, we are using value in cur whose bw is less than current bw
        
        same column value from prev and left side values from cur    
        1D - Array: 
        we can just update current column using current column and previous column
    */
    vector<int> prev(bag_wt+1,0);

    // base case in memoization
    for(int bw=0;bw<=bag_wt;bw++){

        prev[bw] = ((int)bw/wt[0]) * val[0];
    }

    for(int i=1;i<n;i++){

        for(int bw=0;bw<=bag_wt;bw++){          

            int notTake = prev[bw];        
            int  take = 0;
            if(wt[i]<=bw){
                // add it's value, reduce the bag weight and stay on same item
                // as we can take items any no of items
                take = val[i] + prev[bw-wt[i]];
            }

            prev[bw] = max(take,notTake);
        }
    }

    return prev[bag_wt];
}

int32_t main() {
    fastio();

    int n,bag_wt;
    cin>>n>>bag_wt;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>wt[i];

    // vector<vector<int>> dp(n,vector<int>(bag_wt+1,-1));
    // cout<<maxValue_memo(n-1,bag_wt,wt,val,dp);
    // cout<<maxValue_tabu(n,bag_wt,wt,val);
    // cout<<maxValue_space_op1(n,bag_wt,wt,val);
    cout<<maxValue_space_op2(n,bag_wt,wt,val);
    return 0;
}
/*
Output:
*/
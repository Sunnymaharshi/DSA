// Problem Link: https://bit.ly/3KHpP3v
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int  maxValue_memo(int i,int bag_wt,vector<int> &wt, vector<int> &val,vector<vector<int>> &dp){

    if(i==0){               // final item

        if(wt[i]<=bag_wt)       // can this item fit in our bag
            return val[i];      // return item value
        else
            return 0;           // we cannot take this item, 0 value
    }

    if(dp[i][bag_wt]!=-1)           // already computed
        return dp[i][bag_wt];

    int notTake  = maxValue_memo(i-1,bag_wt,wt,val,dp);     // move to next item

    int take = INT_MIN;         // negative value to ignore if item cannot fit in the bag
    if(wt[i]<=bag_wt)           // can this item fit into the bag
        // add this item value and reduce bag weight, move to next item
        take = val[i] + maxValue_memo(i-1,bag_wt-wt[i],wt,val,dp);

    return dp[i][bag_wt] = max(take,notTake);               // store before returning
}

int maxValue_tabu(int n,int bag_wt,vector<int> &wt,vector<int> &val){

    vector<vector<int>>  dp(n,vector<int>(bag_wt+1,0));

    // base cases in memo, we can take final item if bag_wt >= final item weight
    // for all bag_wt's >= final item weight, we can take final item
    for(int W=wt[0];W<=bag_wt;W++){

        dp[0][W] = val[0];    
    }
    
    for(int i=1;i<n;i++){           // from second item to last

        for(int W=0; W<=bag_wt;W++){            // for all possible bag_wt's

            int notTake  = dp[i-1][W];          // get max value from previous item for this bag weight

            int take = INT_MIN;             // negative value to ignore if item cannot fit in the bag
            if(wt[i]<=W)                    // can this item fit into the bag of weight W
                take = val[i] + dp[i-1][W-wt[i]];

            dp[i][W] = max(take,notTake);
        }
    }
    return dp[n-1][bag_wt];                 // max value for bag_wt, considering 0 to n-1th index items
}

int maxValue_space_op(int n,int bag_wt,vector<int> &wt,vector<int> &val){

    // In tabulation, we're just using previous item values to compute current item values
    vector<int> prev(bag_wt+1,0), cur(bag_wt+1,0);

    // base cases in memo, we can take final item if bag_wt >= final item weight
    // for all bag_wt's >= final item weight, we can take final item
    for(int W=wt[0];W<=bag_wt;W++){

        prev[W] = val[0];    
    }
    
    for(int i=1;i<n;i++){           // from second item to last

        for(int W=0; W<=bag_wt;W++){            // for all possible bag_wt's

            int notTake  = prev[W];             // get max value from previous item for this bag weight

            int take = INT_MIN;             // negative value to ignore if item cannot fit in the bag
            if(wt[i]<=W)                    // can this item fit into the bag of weight W
                take = val[i] + prev[W-wt[i]];

            cur[W] = max(take,notTake);
        }

        prev = cur;                     // make current item as previous
    }
    return prev[bag_wt];                // max value for bag_wt, considering 0 to n-1th index items
}
int maxValue_space_op_1ar(int n,int bag_wt,vector<int> &wt,vector<int> &val){

    /*
        In space_op function, for computing take value,
        take = prev[W-wt[i]], we're using value from index less than W.
        notTake is same value as prev for that index
        if we fill prev array value from right to left, we can overwrite prev array values
        without need of cur array as we're using value which is on left side.

        left side of current index act as prev array and right side of current index act  
        as cur array.
    */
    vector<int> prev(bag_wt+1,0);

    // base cases in memo, we can take final item if bag_wt >= final item weight
    // for all bag_wt's >= final item weight, we can take final item
    for(int W=wt[0];W<=bag_wt;W++){

        prev[W] = val[0];    
    }
    
    for(int i=1;i<n;i++){           // from second item to last

        for(int W=bag_wt; W>=0;W--){            // for all possible bag_wt's from right to left

            int notTake  = prev[W];             // get max value from previous item for this bag weight

            int take = INT_MIN;             // negative value to ignore if item cannot fit in the bag
            if(wt[i]<=W)                    // can this item fit into the bag of weight W
                take = val[i] + prev[W-wt[i]];          // value from left side

            prev[W] = max(take,notTake);
        }
    }
    return prev[bag_wt];                // max value for bag_wt, considering 0 to n-1th index items
}
int32_t main() {
    fastio();

    int n,bag_wt;
    cin>>n;
    vector<int> wt(n),val(n);
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    cin>>bag_wt;
    // // bag_wt+1 since we need index for bag_wt
    // vector<vector<int>> dp(n,vector<int>(bag_wt+1,-1));
    // cout<<maxValue_memo(n-1,bag_wt,wt,val,dp);
    // cout<<maxValue_tabu(n,bag_wt,wt,val);
    // cout<<maxValue_space_op(n,bag_wt,wt,val);
    cout<<maxValue_space_op_1ar(n,bag_wt,wt,val);
    return 0;
}
/*
Output:
4
1 2 4 5
5 4 8 6
5
13
*/
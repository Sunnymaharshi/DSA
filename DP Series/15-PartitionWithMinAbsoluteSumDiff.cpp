// Problem Link: https://bit.ly/3t62bqQ
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int minSubsetSumDiff_tabu(int n,vector<int> &arr){

    int totalSum = 0;
    for(auto i:arr)
        totalSum += i;
    
    /* Subset Sum with target K algorithm */
    // totalSum+1 since it is zero based indexing, we need have index with totalSum also
    vector<vector<bool>> dp(n,vector<bool>(totalSum+1,0));

    // base cases in memoization
    for(int i=0;i<n;i++)           // for any index if target is 0
        dp[i][0] = true;
    
    if(arr[0]<=totalSum)           // final element must be less than target to consider it
        dp[0][arr[0]] = true;           

    for(int i=1;i<n;i++){

        for(int target=1;target<=totalSum;target++){

            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i]<=target){
                take = dp[i-1][target-arr[i]];     // reduce the target
            }

            // either of these true, we found subset with target as sum
            dp[i][target] = notTake || take;   

        }
    }

    /*  
        dp[n-1][t] tells you whether there exists a subset with sum as t
        in elements from 0 to n-1 index of array.
    */

   int minDiff  = (int)1e9;
   // if we found subset with s1, then subset with totalSum-s1 also exists
   // so we only check upto totalSum/2
   for(int s1=0;s1<=totalSum/2; s1++){

       if(dp[n-1][s1]){             // subset with sum as s1 exists

            int s2 = totalSum - s1;     // other subset sum
            minDiff = min(minDiff, abs(s1-s2));
       }
   }

   return minDiff;
}

int minSubsetSumDiff_space_op(int n,vector<int> &arr){

    int totalSum = 0;
    for(auto i:arr)
        totalSum += i;

    
    // we're just using values of previous index to compute values of current index
    vector<bool> prev(totalSum+1,0),cur(totalSum+1,0);

    // base cases in memoization
    prev[0] = true;                     // for target as 0
     
    if(arr[0]<=totalSum)           // final element must be less than target to consider it
        prev[arr[0]] = true;           

    for(int i=1;i<n;i++){

        cur[0] = true;                          // for target as 0
        for(int target=1;target<=totalSum;target++){

            bool notTake = prev[target];
            bool take = false;
            if(arr[i]<=target){
                take = prev[target-arr[i]];     // reduce the target
            }

            // either of these true, we found subset with target as sum
            cur[target] = notTake || take;   
        }
        prev = cur;                 // make current values as previous
    }

    /*  
        prev[t] tells you whether there exists a subset with sum as t
        in elements from 0 to n-1 index of array.
    */

   int minDiff  = (int)1e9;
   // if we found subset with s1, then subset with totalSum-s1 also exists
   // so we only check upto totalSum/2
   for(int s1=0;s1<=totalSum/2; s1++){

       if(prev[s1]){             // subset with sum as s1 exists

            int s2 = totalSum - s1;     // other subset sum
            minDiff = min(minDiff, abs(s1-s2));
       }
   }

   return minDiff;
}

int32_t main() {
    fastio();

    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // cout<<minSubsetSumDiff_tabu(n,arr);
    cout<<minSubsetSumDiff_space_op(n,arr);
    return 0;
}
/*
Output:
*/
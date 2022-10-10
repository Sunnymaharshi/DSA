// Problem Link: https://bit.ly/3rVoIoq
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int lis_memo(int ind, int prev_ind,int n, int arr[], vector<vector<int>> &dp){

    if(ind == n)            // out of array
        return 0;

    if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];
    
    // not pick
    int len = lis_memo(ind+1,prev_ind,n,arr,dp);

    // pick if it is first element or it is greater than previously picked element
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){

        len = max(len, 1 + lis_memo(ind+1,ind,n,arr,dp));
    }

    return dp[ind][prev_ind+1] = len;
}

int lis_tabu(int n,int arr[]){

    // Base case ind==n return 0
    // already initialised with 0s
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int ind= n-1; ind>=0;ind--){

        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
            
            // not pick
            int len = dp[ind+1][prev_ind+1];

            // pick if it is first element or it is greater than previously picked element
            // ind+1 as we've shifted dp to  +1
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){

                len = max(len, 1 + dp[ind+1][ind+1]);
            }

            dp[ind][prev_ind+1] = len;
        }
    }
    return dp[0][0];

}

int lis_tabu_space_op(int n,int arr[]){

    vector<int> next(n+1,0);
    vector<int> current(n+1,0);

    for(int ind= n-1; ind>=0;ind--){

        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
            
            // not pick
            int len = next[prev_ind+1];

            // pick if it is first element or it is greater than previously picked element
            // ind+1 as we've shifted dp to  +1
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){

                len = max(len, 1 + next[ind+1]);
            }

            current[prev_ind+1] = len;
        }
        next = current;
    }

    return current[0];
}

// tabulation method

int lis_table(int n,int arr[]){

    int lis = 0;
    // min lis for every element is 1
    vector<int> dp(n,1);

    // check all prev elements which can be part of lis with current element

    for(int cur=0;cur<n;cur++){

        for(int prev=0;prev<cur;prev++){

            // can be included
            if(arr[prev]<arr[cur]){

                dp[cur] = max(dp[cur], 1+dp[prev]);
            }

        }
        // dp[cur] specifies length of longest lis ending at current element
        lis = max(lis,dp[cur]);
    }
    
    return lis;
}

// as we only need len, we can rewrite the sequence to get max len
// we use binary search to rewrite the element as it is sorted
// we rewrite first element that is just greater than current element
int lis_binarySearch(int n, int arr[]){

    vector<int> temp;
    temp.push_back(arr[0]);
    int lis_len = 1;

    for(int i=1;i<n;i++){

        if(arr[i] > temp.back()){       // can be included

            temp.push_back(arr[i]);
            lis_len++;
        }      
        else{

            /*  it can be included before
                as we don't need lis print we can place this in possible position                 
                we find just greater ele than this and replace it with
                current element.
                it won't change our lis len, but it is not lis.
                to find next greater ele we use binary search
            */
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return lis_len;
}


int main() {
    fastio();

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // n+1 as prev_ind starts with -1
    vector<vector<int>> dp(n,vector<int>(n+1,-1));

    // cout<<lis_memo(0,-1,n,arr,dp);
    // cout<<lis_tabu(n,arr);
    // cout<<lis_tabu_space_op(n,arr);
    // cout<<lis_table(n,arr);
    cout<<lis_binarySearch(n,arr);
    
}

/*
Output:
6
5 4 11 1 16 8
3
*/
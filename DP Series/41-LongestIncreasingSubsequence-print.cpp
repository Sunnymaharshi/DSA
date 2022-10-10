// 
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// tabulation method

void lis_print(int n,int arr[]){

    int lis_len = 0;
    // min lis for every element is 1
    vector<int> dp(n,1);

    // store prev element index in an array
    vector<int> hash(n);
    int lastIndex = 0;
            

    // check all prev elements which can be part of lis with current element

    for(int cur=0;cur<n;cur++){
        
        hash[cur] = cur;

        for(int prev=0;prev<cur;prev++){

            // can be included
            if(arr[prev]<arr[cur] && 1+dp[prev]>dp[cur]){

                dp[cur] = 1+dp[prev];
                hash[cur] = prev;
            }

        }
        // dp[cur] specifies length of longest lis ending at current element
        if(dp[cur]>lis_len){

            lis_len = dp[cur];
            lastIndex = cur;
        }
    }
    
    int lis[lis_len];
    int ind = lis_len-1;
    lis[ind--] = arr[lastIndex];

    while(hash[lastIndex]!=lastIndex){

        lastIndex = hash[lastIndex];
        lis[ind--] = arr[lastIndex];
    }
    for(auto i:lis){
        cout<<i<<sp;
    }
}

int main() {
    fastio();

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    lis_print(n,arr);

    
}

/*
Output:
6
5 4 11 1 16 8
5 11 16 
*/
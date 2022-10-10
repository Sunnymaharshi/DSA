// Problem Link: https://bit.ly/3rON1Ef
#include<iostream>
#include<vector>
#include<algorithm>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


vector<int> lds_print(vector<int> &arr,int n){

    /*
        sort it 1 4 7 8
        subset (1) -> 4 can be divided by 1
        subset (1 4)-> 7 can't divide by 4
        subset (1 4)-> 8 can be divided by 4 so 1 can also divide 8
        made as longest divisible subsequence similar to lis_print
    */

    int lds_len = 0;
    // min lds for every element is 1
    vector<int> dp(n,1);

    // store prev element index in an array
    vector<int> hash(n);
    int lastIndex = 0;
            
    sort(arr.begin(),arr.end());                // sort the array
    // check all prev elements which can be part of lds with current element

    for(int cur=0;cur<n;cur++){
        
        hash[cur] = cur;

        for(int prev=0;prev<cur;prev++){

            // if it is divisible
            if(arr[cur]%arr[prev]==0 && 1+dp[prev]>dp[cur]){

                dp[cur] = 1+dp[prev];
                hash[cur] = prev;
            }

        }
        // dp[cur] specifies length of longest lds ending at current element
        if(dp[cur]>lds_len){

            lds_len = dp[cur];
            lastIndex = cur;
        }
    }
    
    vector<int> lds(lds_len);
    int ind = lds_len-1;
    lds[ind--] = arr[lastIndex];

    while(hash[lastIndex]!=lastIndex){

        lastIndex = hash[lastIndex];
        lds[ind--] = arr[lastIndex];
    }
    
    return lds;

}
int main() {
    fastio();

    int n;
    cin>>n;
    vector<int> arr(n), lds;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    lds = lds_print(arr,n);
    for(auto i: lds)
        cout<<i<<sp;
    
}

/*
Output:
5
1 16 7 8 4
1 4 8 16 
*/
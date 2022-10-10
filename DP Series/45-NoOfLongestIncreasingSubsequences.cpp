// Problem Link: https://bit.ly/3fTRGiz
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int noOflis(vector<int> &arr, int n){

    vector<int> dp(n,1);     
    vector<int> cnt(n,1);    // count
    int lis_len = 0;
    /*
        dp[cur] is lis len upto cur ele
        cnt[cur] is count of lis len upto cur ele
    */
    for(int cur=0; cur<n; cur++){

        for(int prev=0;prev < cur; prev++){

            // if lis length increase, it will take count from prev ele
            // as we need count for max length
            if(arr[prev] < arr[cur] && dp[prev] + 1 > dp[cur]){

                dp[cur] = 1 + dp[prev];
                cnt[cur] = cnt[prev];
            }
            // if we get same len with other element, we add count of that ele
            else if(arr[prev] < arr[cur] && dp[prev] + 1 == dp[cur]){

                cnt[cur] += cnt[prev];
            }
        }

        lis_len = max(lis_len,dp[cur]);
    }

    int lis_cnt = 0 ;

    // lis can be anywhere, we add all lis counts
    for(int i=0;i<n;i++){

        if(dp[i]==lis_len){
            lis_cnt += cnt[i];
        }
    }

    return lis_cnt;
}
int main() {
    fastio();

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<noOflis(arr,n);    
}

/*
Output:
5
50 3 90 60 80
2
*/
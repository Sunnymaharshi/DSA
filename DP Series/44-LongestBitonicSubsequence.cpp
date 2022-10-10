// Problem Link: https://bit.ly/3r4o1JB
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// Bitonic means subsequence that is increasing and then decreasing
// it can just be increasing or decreasing also

int lbs(vector<int> &arr, int n){

    vector<int> dp_forward(n,1);    // lis left to right
    

    // lis code
    for(int cur=0; cur<n; cur++){

        for(int prev=0;prev < cur; prev++){

            if(arr[prev] < arr[cur] && dp_forward[prev] + 1 > dp_forward[cur]){

                dp_forward[cur] = 1 + dp_forward[prev];
            }
        }
    }

    vector<int> dp_backward(n,1);   // lis right to left i.e decreasing order

    // lis code from backwards
    for(int cur= n-1; cur >=0 ; cur--){

        for(int prev=n-1;prev > cur; prev--){

            if(arr[prev] < arr[cur] && dp_backward[prev] + 1 > dp_backward[cur]){

                dp_backward[cur] = 1 + dp_backward[prev];
            }
        }
    }

    int lbs = 0;

    for(int i=0; i<n;i++){

        // -1 as both have current element as common
        lbs = max(lbs, dp_forward[i] + dp_backward[i] - 1);
    }

    return lbs;
}
int main() {
    fastio();

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<lbs(arr,n);    
}

/*
Output:
5 
1 2 1 2 1
3
*/
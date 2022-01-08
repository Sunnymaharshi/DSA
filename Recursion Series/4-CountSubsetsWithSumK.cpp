#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int subsetsWithSumK(int i,int n,int sum,int target,vector<int> &arr,vector<int> &sub){
    
    if(i==n){
        if(sum==target){
            return 1;           // found one
        }
        return 0;               // not found
    }

    sub.emplace_back(arr[i]);       // take ith element into subsequence
    sum += arr[i];
    int with = subsetsWithSumK(i+1,n,sum,target,arr,sub);  // subsequence with ith element
    sub.pop_back();                 // remove ith element   
    sum -= arr[i];     
    int withOut = subsetsWithSumK(i+1,n,sum,target,arr,sub);  // subsequence without ith element

    return with + withOut;
}

int32_t main() {
    fastio();
    int n,target;
    cin>>n>>target;
    vector<int> arr(n,0),sub;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<subsetsWithSumK(0,n,0,target,arr,sub);
    return 0;
}
/*
Output:
5 10
1 1 3 2 5
2
*/
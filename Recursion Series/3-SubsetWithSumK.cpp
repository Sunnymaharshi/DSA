#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool subsetWithSumK(int i,int n,int sum,int target,vector<int> &arr,vector<int> &sub){
    
    if(i==n){
        if(sum==target){
            for(auto ele:sub){
                cout<<ele<<sp;
            }
            cout<<nl;
            return true;        // found Subsequence with Sum as target
        }
        return false;           // not found
    }

    sub.emplace_back(arr[i]);       // take ith element into subsequence
    sum += arr[i];
    if(subsetWithSumK(i+1,n,sum,target,arr,sub)==true){  // subsequence with ith element
        return true;
    }
    sub.pop_back();                 // remove ith element   
    sum -= arr[i];     
    if(subsetWithSumK(i+1,n,sum,target,arr,sub)==true){ // subsequence without ith element
        return true;
    }

    return false;
}

int32_t main() {
    fastio();
    int n,target;
    cin>>n>>target;
    vector<int> arr(n,0),sub;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(subsetWithSumK(0,n,0,target,arr,sub)==false){
        cout<<"Subset with sum "<<target<<" not found"<<nl;
    }
    return 0;
}
/*
Output:
5 10
1 1 3 2 5
1 1 3 5 
*/
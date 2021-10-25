// Time Complexity - O(2^N * N)
// N is for printing subset
#include<iostream>
#include<vector>
using namespace std;
#define int long long

void findSubsetsSumDivByK(int i,int sum,int k, vector<int> &arr, vector<int> &subset){

    if(i==arr.size()){            // after traversing all array elements
        
        if(subset.size()!=0 && sum%k==0){  // if sum is divisible by k and it is not an empty subset
            for(auto ele:subset){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return;                     // end the function
    }
    subset.push_back(arr[i]);       // add ith element to subset
    findSubsetsSumDivByK(i+1,sum+arr[i],k,arr,subset);   // add ith element to sum

    subset.pop_back();               // do not add ith element to subset
    findSubsetsSumDivByK(i+1,sum,k,arr,subset);  
}
int32_t main() {

    int n,k;
    cin>>n;
    vector<int> arr(n,0), subset;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    cout<<"subsets who sum is divisible by "<<k<<endl;
    findSubsetsSumDivByK(0,0,k,arr,subset);
    return 0;
}
/*
Output:
3
1 2 5
2
subsets who sum is divisible by 2
1 2 5
1 5
2
*/
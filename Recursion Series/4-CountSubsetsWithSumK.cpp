// Time Complexity - O(2^N)
#include<iostream>
#include<vector>
using namespace std;
#define int long long

int countSubsetsSumDivByK(int i,int sum,int k, vector<int> &arr){

    if(i==arr.size()){            // after traversing all array elements
        
        if(sum%k==0){             // if sum is divisible by k and it is not an empty subset

            return 1;    // valid
        }
        return 0;        // not valid             
    }
    int ans=0;
    ans += countSubsetsSumDivByK(i+1,sum+arr[i],k,arr);   // add ith element to sum

    ans += countSubsetsSumDivByK(i+1,sum,k,arr);          // do not add ith element to sum
    
    // ans stores no of subsets with sum divisible by k for subsets with and without arr[i]
    return ans;
}
int32_t main() {

    int n,k;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    // empty subset sum is 0, which satisfies sum%k==0, hence we subract 1
    cout<<"no of subsets who sum is divisible by "<<k<<" is:"<<countSubsetsSumDivByK(0,0,k,arr)-1;
    return 0;
}
/*
Output:
3
1 5 8
3
no of subsets who sum is divisible by 3 is:2
*/
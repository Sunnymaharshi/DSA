// Problem Link: https://bit.ly/3r8mG5b
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int countPartitionsWithDiff(int n,int diff,vector<int> &arr){
    /*
        divide the array into 2 subsets with
        s1-s2 = d, s1>=s2
        as s1+s2 = totalSum
        s1 = totalSum - s2
        then (totalSum - s2) - s2 = d
        s2 = (totalSum -d)/2
        we need to find no of subsets with sum (totalSum-d)/2
        totalSum-d>=0 since all elements >= 0,  sum also >= 0
        s2 can't be a decimal number, so totalSum-d must be divisible by 2
    */
   int mod = (int) 1e9+7;
    int totalSum = 0;
    for(auto i:arr)
        totalSum += i;
    
    if(totalSum - diff<0 || (totalSum - diff)%2)
        return 0;
    

    /* count subsets with target as sum algorithm */
    int target = (totalSum - diff)/2;
    vector<int> prev(target+1,0),cur(target+1,0);

    // if final element is 0
    if(arr[0]==0)               // gives same sum for take and not take
        prev[0] = 2;
    else
        prev[0] = 1;                   

    // final element must be our target to consider it
    // !=0, it should not alter above case
    if(arr[0]!=0 && arr[0]<=target)  
        prev[arr[0]] = 1;
      
    for(int i=1;i<n;i++){

        
        for(int s=0;s<=target;s++){
            
            int notTake = prev[s];
            int take = 0;
            if(arr[i]<=s)                      // check if element is valid
                take = prev[s-arr[i]];      // reduce the target
                
            // sub problem : subsets with target s in elements from 0 to ith index
            cur[s] = (take%mod+notTake%mod)%mod;           
        }
        prev = cur;                 // make current index as previous index
    }

    return prev[target];
}

int32_t main() {
    fastio();

    int n,d;
    cin>>n>>d;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<countPartitionsWithDiff(n,d,arr);
    
    return 0;
}
/*
Output:
5 1
3 2 2 5 1
3
*/
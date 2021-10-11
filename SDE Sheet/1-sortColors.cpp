// normal sort algo- O(nlogn)
// counting sort algo-2-passes- O(n)
/* dutch national flag algo
    3-pointers
    low,min,high
    low=mid=start, high=last
    0-low-1 are 0's
    high+1-n are 2's
    stop when mid>high
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int low=0,mid=0,high=n-1;
    while(mid<=high){

        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            //increase low and mid -elements are processed
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            //1's will be in middle -no need to swap
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            //2's will be after high -we should process previous high element
            // don't increase mid
            high--;
        }
    }
    for(int i:nums) cout<<i<<" ";
    

}
/*
output:
7
2 2 2 1 1 0 0
0 0 1 1 2 2 2 
*/
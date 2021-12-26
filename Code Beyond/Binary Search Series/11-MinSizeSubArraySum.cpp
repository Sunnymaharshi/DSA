/* 
min size 1
max size n
with increase in size sum will also increases
this means it is monotonically increasing function
*/
#include<iostream>
#include<vector>
using namespace std;
bool isPossible(int  arr[], int n, int target, int size){

    int sum=0;
    for(int i=0;i<size;i++)
        sum+=arr[i];
    int l=0,r=size, maxsum;
    maxsum = sum;
    while(r!=n){            // sliding windwow
        sum -= arr[l];
        l++;
        sum += arr[r];
        r++;
        maxsum = max(maxsum,sum);
    }
    return maxsum>=target;

}
int findMinSize(int arr[], int n, int target){
    int low=1, high=n;
    bool possible = false;
    while(low<high){
        int mid=low + (high-low)/2;
        if(isPossible(arr,n,target,mid)){
            high = mid;                     // mid might be the ans
            possible = true;
        }
        else    
            low = mid+1;                    // search on right part
    }
    if(possible) return low;
    return 0;   

}
int main() {

    int n, target;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>target;
    cout<<"min size of sub array:"<<findMinSize(arr,n,target);
    return 0;
}

/*
Output;
6
2 3 1 2 4 3
7
min size of sub array:2
*/
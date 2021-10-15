/*
minimum max sweetness will be min(arr) when we divide choclate into n subrrays
maximum max sweetness will be sum(arr) when we divide choclate into 1 subarray
range min(arr) to sum(arr)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool SubArraysWithAtleast(int arr[], int n, int sweet, int chunks){

    int sum=0,count=0;
    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum>=sweet){
            count++;
            sum=0;
        }
    }
    return count>=chunks;

}
int findMaxMinimumSweet(int arr[], int n, int m){
    int low = *min_element(arr,arr+n), high =0,ans;
    for(int i=0;i<n;i++)
        high += arr[i];
    ans=low;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(SubArraysWithAtleast(arr,n,mid,m)){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans;
}
int main() {

    int n,m;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
    cout<<"maximum min sweet:"<<findMaxMinimumSweet(arr,n,m+1);


    return 0;
}
/*
9
1 2 3 4 5 6 7 8 9
5
maximum min sweet:6
*/
/*
with increase in divisor sum will decrease
this means it is monotonically decreasing function
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int findSum(vector<int> arr, int divisor){

    int sum=0;
    for(int i=0; i<arr.size(); i++)
        sum += ceil((float) arr[i]/divisor);
    return sum;
}
int findMinDivisor(vector<int> arr, int threshold){

    // min divisor is 1, max divisor is max(arr) 
    // since any no greater than max(arr) will give same sum as max(arr)

    int low=1,high = *max_element(arr.begin(),arr.end());
    while(low<high){
        int mid = low + (high-low)/2;
        if(findSum(arr,mid)<=threshold) // search on left to find smallest divisor
            high = mid;                 // mid might be the answer
        else
            low = mid+1;                // search on right part
    }
    return low;

}
int main() {

    int n, threshold;
    cin>>n;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>threshold;
    cout<<"min divisor:"<<findMinDivisor(arr,threshold);

    return 0;
}
/*
5
44 22 33 11 1
5
min divisor:44
*/
#include<iostream>
using namespace std;
/*
biggest number x such that x*x <= n
*/
int sqrt(int n){
    int low=1,high=n/2,ans=1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid*mid <= n){
            ans = mid;      // store answer
            low = mid+1;    // search on right half
        }
        else
            high = mid -1;  // search on left half
    }
    return ans;
}
int main() {

    int n;
    cin>>n;
    cout<<"integer square root of "<<n<<":"<<sqrt(n);
    return 0;
}
/*
Output:
170
integer square root of 170:13
*/
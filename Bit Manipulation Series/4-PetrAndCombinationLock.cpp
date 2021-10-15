// Time  Complexity O(n*(2^n)) 
// will not work is n is very large
// https://codeforces.com/problemset/problem/1097/B
#include<iostream>
#include<vector>
using namespace std;
bool isPossible(vector<int> &v, int n){
    for(int ss=0; ss<=(1<<n)-1; ss++){      // 0 to 2^n-1
        int clock=0;   
        for(int bit=0; bit<n; bit++){
            if(ss&(1<<bit))             // if bit is set, rotate to right
                clock += v[bit];
            else
                clock -= v[bit];        // if bit is not set, rotate to left
        }
        if(clock%360==0)
            return true;
    }
    return false;
}
int main() {

    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(isPossible(arr,n))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}

/*
3
10 20 30
YES
*/
/* https://cses.fi/problemset/task/1646/
Time Complexity is O(1) for query
Space Complexity is O(n)
*/
#include<iostream>
using namespace std;
#define int long long
int sumQuery(int l, int r, int prefix[])
{
    if(l==0)                // prefix[r] contains sum  0 to r
        return prefix[r];
    return prefix[r]-prefix[l-1]; 
}
int32_t main() {

    int n,q;
    cin>>n>>q;
    int arr[n],prefix[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = arr[i] + prefix[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<sumQuery(l,r,prefix)<<endl;
    }

    return 0;
}
/*
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
11
2
24
4
*/
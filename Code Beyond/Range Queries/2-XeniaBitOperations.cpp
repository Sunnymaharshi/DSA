// https://codeforces.com/problemset/problem/339/D
#include<iostream>
#include<vector>
#include<cmath>
#define nl "\n"
#define int long long
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void buildSeg(int ind, int low, int high,int arr[],int seg[],int OR){

    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid = (low + high)/2;
    buildSeg(2*ind+1,low,mid,arr,seg,!OR);
    buildSeg(2*ind+2,mid+1,high,arr,seg,!OR);
    if(OR)
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];


}
void update(int ind,int low,int high,int i,int val,int OR,int arr[],int seg[]){

    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid = (low+high)/2;
    if(i<=mid)
        update(2*ind+1,low,mid,i,val,!OR,arr,seg);
    else
        update(2*ind+2,mid+1,high,i,val,!OR,arr,seg);
    if(OR)
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];

}
int32_t main() {

    fastio();
    int n,m;
    cin>>n>>m;
    int els = pow(2,n);
    int arr[els];
    int seg[4*els];
    for(int i=0;i<els;i++)    cin>>arr[i];
    if(n%2==0)
        buildSeg(0,0,els-1,arr,seg,0);          // start with XOR
    else
        buildSeg(0,0,els-1,arr,seg,1);          // start with OR
    while(m--){
        int i,val;
        cin>>i>>val;
        i--;
        if(n%2==0)
            update(0,0,els-1,i,val,0,arr,seg);    // start with XOR
        else
            update(0,0,els-1,i,val,1,arr,seg);    // start with OR
        
        cout<<seg[0]<<nl;

    }

    


    return 0;
}
/*
Output:
2 4
1 6 3 5
1 4
3 4
1 2
1 2
1
3
3
3
*/
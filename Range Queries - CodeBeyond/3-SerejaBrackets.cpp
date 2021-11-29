// https://codeforces.com/problemset/problem/380/C
#include<iostream>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
struct info {
    int open,close,full;
    info(){
        open=0;
        close=0;
        full =0;
    }
    info(int _open,int _close, int _full){
        open=_open;
        close=_close;
        full=_full;
    }
};
info merge(info left, info right){
    info ans = info();
    ans.full = left.full+right.full+min(left.open,right.close);
    ans.open = left.open + right.open - min(left.open,right.close);
    ans.close = left.close + right.close - min(left.open,right.close);
    return ans;
}
void buildSeg(int ind, int low,int high, info seg[], string s){

    if(low==high){
        seg[ind] = info(s[low]=='(',s[low]==')',0);
        return;
    }
    int mid= (low+high)/2;
    buildSeg(2*ind+1,low,mid,seg,s);
    buildSeg(2*ind+2,mid+1,high,seg,s);
    seg[ind] = merge(seg[2*ind+1],seg[2*ind+2]);

}
info query(int ind, int low,int high,int l,int r,  info seg[]){

    if(r<low || l>high) return info();         // no overlap

    if(low >= l && high <= r)   return seg[ind];    // completely overlap

    int mid = (low + high)/2;
    info left = query(ind*2+1,low,mid,l,r,seg);
    info right = query(ind*2+2,mid+1,high,l,r,seg);

    return merge(left,right);
}
int32_t main() {

    fastio();
    string s;
    cin>>s;
    int n=s.size();
    info seg[4*n+1];
    buildSeg(0,0,n-1,seg,s);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<query(0,0,n-1,l,r,seg).full * 2<<nl;
    }

    return 0;
}
/*
Output:
*/
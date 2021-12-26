// https://www.codechef.com/CENS2020/problems/CENS20A
// similar to scanline algo but with rectangles in 2D array
#include<iostream>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void solve(){

    int r,c;
    char chr;
    cin>>r>>c;
    int mat[r+1][c+1];
    int pre[r+1][c+1]={0};
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>chr;
            mat[i][j] = chr-'0';
        }
    }
    
    int q;
    cin>>q;
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        pre[r1][c1] += 1;              // top left cell
        if(c2<c)
            pre[r1][c2+1] -= 1;        // horizontal prefix end
        if(r2<r)
            pre[r2+1][c1] -= 1;        // vertical prefix end
        if(r2<r && c2<c)
            pre[r2+1][c2+1] += 1;      
        // this cell will affect 2 times while adding col wise
        // and row wise, hence discard 1 time with adding 1
    }

    for(int j=1;j<=c;j++){                // prefix sum verticaly for every column
        for(int i=2;i<=r;i++){
            pre[i][j] += pre[i-1][j];
        }        
    }
    for(int i=1;i<=r;i++){                // prefix sum horizontally for every row
        for(int j=2;j<=c;j++){
            pre[i][j] += pre[i][j-1];       
        }
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(pre[i][j]%2==1)                  // updated odd times, bit flipped
                cout<<1-mat[i][j];
            else
                cout<<mat[i][j];
        }
        cout<<nl;
    }


}
int main() {

    fastio();
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    } 

    return 0;
}
/*
Output:
*/
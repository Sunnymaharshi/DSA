#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
to print paths in lexicographically increasing order
we just need to choose directions in lexicographically increasing order.
*/
void paths(int i,int j,int n,string path,vector<vector<int>> &mat,
        vector<vector<int>> &vis,vector<string> &ans){

    if(i==n-1 && j==n-1){       // last cell
        ans.push_back(path);
        return;        
    }
    // choose directions in lexicographically increasing order
    // down,left,right,up 
    string d="DLRU";
    int di[] = {1,0,0,-1};
    int dj[] = {0,-1,1,0};  

    for(int k=0;k<4;k++){

        int newi = i+di[k];
        int newj = j+dj[k];

        if(newi>=0 && newi<n && newj>=0 && newj<n && mat[newi][newj]==1
            && !vis[newi][newj]){

            // new cell must be inside matrix and it's value is 1 and not visited

            vis[i][j] = 1;        // mark current cell as visited
            // go to the new possible cell
            paths(newi,newj,n,path+d[k],mat,vis,ans);  

            // mark it as unvisited when you come back i.e after finishing above call
            vis[i][j] = 0;   
        }

    }

}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<string> ans;
    string path="";
    vector<vector<int>> mat(n,vector<int>(n,0)),vis(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    if(mat[0][0]==1)            // starting cell value must be 1 to move further
        paths(0,0,n,path,mat,vis,ans);

    for(auto path:ans){
        cout<<path<<nl;
    }

    return 0;
}
/*
Output:
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
DDRDRR
DRDDRR
*/
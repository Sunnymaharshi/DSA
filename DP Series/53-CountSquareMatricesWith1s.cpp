// Problem Link: https://bit.ly/3tYAUY7
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// dp
// how many square matrices with 1s with dp[i][j] as bottom right corner
int countSquaresWith1(int n,int m, vector<vector<int>> &mat){

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // copy first row and column, as they are 1x1 matrices
    for(int i=0;i<n;i++)
        dp[i][0] = mat[i][0];
    for(int j=0;j<m;j++)
        dp[0][j] = mat[0][j];
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){

            // if current element is 1, find min of left, top and diagonal
            // add 1 to it, as element itself is 1x1 matrix
            if(mat[i][j] == 1)
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1])) + 1;
            else
                dp[i][j] = 0;
        }
    }

    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            count += dp[i][j];
        }
    }

    return count;
}
int main() {
    fastio();

    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    
    cout<<countSquaresWith1(n,m,mat)<<nl;
    
    return 0;    
}

/*
Output:
3 4
0 1 1 0
1 1 1 0
0 0 1 0
7
*/
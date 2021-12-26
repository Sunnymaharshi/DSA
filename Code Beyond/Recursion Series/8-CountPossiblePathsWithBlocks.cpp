// if mat[i][j]=0, there is block in that cell, you cannot go through that cell
#include<iostream>
#include<vector>
using namespace std;
int ci[] = {1,0,0,-1}, cj[] = {0,-1,1,0};           // change in i and j for four sides


int countPossiblePaths(int i,int j,int r,int c, vector<vector<int>> &vis, vector<vector<int>> &mat){

    // if indexes gone outside matrix or it is already visited or cell value is 0
    if(i>=r || j>=c || i<0 || j<0 || vis[i][j]==1 || mat[i][j]==0) 
        return 0;             // invalid path

    if(i==r-1 && j==c-1)      // reached end of matrix
        return 1;             // valid path
    


    vis[i][j] = 1;            // make current cell as visited        
    int count=0;
    for(int ind=0;ind<4;ind++){

        count +=  countPossiblePaths(i+ci[ind],j+cj[ind],r,c,vis,mat);
    }
    
    
    vis[i][j]=0;    // we you go back from this cell mark it as unvisited
    return count;

}
int32_t main() {

    int r,c;
    cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c,0)), vis(r,vector<int>(c,0));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"no of paths to reach end with blocks:"<<countPossiblePaths(0,0,r,c,vis,mat);

    return 0;
}
/*
Output:
3 3
1 1 0
0 1 1
1 1 1
no of paths to reach end with blocks:2
*/
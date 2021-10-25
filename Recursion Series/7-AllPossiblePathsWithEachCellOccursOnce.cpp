// you can move all four directions but cell must not occur more than once in the path
#include<iostream>
#include<vector>
using namespace std;
#define int long long
// to print in lexicographical order you just need to call directions in sorted order

int ci[] = {1,0,0,-1}, cj[] = {0,-1,1,0};           // change in i and j for four sides
string cp= "DLRU";                                  // change in path

void findAllPathsCellOnce(int i, int j, int r,int c, vector<vector<int>> &vis, string path){

    if(i>=r || j>=c || i<0 || j<0 || vis[i][j]==1) // if indexes gone outside matrix or it is already visited 
        return;             // end the function

    if(i==r-1 && j==c-1){   // reached end of matrix
        cout<<path<<endl;
        return;             // end function
    }


    vis[i][j] = 1;          // make current cell as visited
    
    /*
    // so many lines of code
    path += "D";            // go down
    findAllPathsCellOnce(i+1,j,r,c,vis,path);          // find paths after going down
    path.pop_back();        // remove D
    
    path += "R";            // go right
    findAllPathsCellOnce(i,j+1,r,c,vis,path);           // find paths after going right
    path.pop_back();        /// remove R

    path += "U";            // go up
    findAllPathsCellOnce(i-1,j,r,c,vis,path);          // find paths after going down
    path.pop_back();        // remove U
    
    path += "L";            // go left
    findAllPathsCellOnce(i,j-1,r,c,vis,path);           // find paths after going right
    path.pop_back();        // remove L
    */

    for(int ind=0;ind<4;ind++){
        path += cp[ind];
        findAllPathsCellOnce(i+ci[ind],j+cj[ind],r,c,vis,path);
        path.pop_back();
    }
    
    // we you go back from this cell mark it as unvisited
    vis[i][j]=0;
    
}

int32_t main() {

    int r,c;
    cin>>r>>c;
    vector<vector<int>> vis(r,vector<int>(c,0));
    // we use visited matrix to avoid going to cell which is already in our path
    cout<<"All possible paths with each cell in the path occurs only once:\n";
    findAllPathsCellOnce(0,0,r,c,vis,"");
    return 0;
}
/*
Output:
3 2
All possible paths with each cell in the path occurs only once:
DDR
DRD
RDD
RDLDR
*/
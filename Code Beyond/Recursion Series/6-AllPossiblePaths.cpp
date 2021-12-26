// all possible paths to reach end(m,n) of the matrix from (0,0)
// you can only move right or down
#include<iostream>
#include<vector>
using namespace std;

void findAllPaths(int i, int j, int r,int c, string path){

    if(i>=r || j>=c)        // if indexes gone outside matrix end the function
        return; 

    if(i==r-1 && j==c-1){   // reached end of matrix
        cout<<path<<endl;
        return;             // end function 
    }

    path += "D";            // go down
    findAllPaths(i+1,j,r,c,path);          // find paths after going down
    path.pop_back();        // remove D
    
    path += "R";            // go right
    findAllPaths(i,j+1,r,c,path);           // find paths after going right
    path.pop_back();        // remove R
    
}
int32_t main() {

    int r,c;
    cin>>r>>c;
    cout<<"All possible paths to reach end of the matrix:\n";
    findAllPaths(0,0,r,c,"");
    return 0;
}
/*
Output:
3 3
All possible paths to reach end of the matrix:
DDRR
DRDR
DRRD
RDDR
RDRD
RRDD
*/
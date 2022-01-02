// https://leetcode.com/problems/n-queens/
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool isSafe(int row,int col,int n,vector<string> &board){

    /*
    since we placing the queen column wise from left to right
    we only need to check if any queen on left side attacks 
    if we place the queen at that place
    */
    int r=row,c=col;
    // top left diagonal
    while(r>=0 && c>=0){
        if(board[r][c]=='Q')    return false;
        r--;
        c--;
    }

    r=row,c=col;
    // check the row
    while(c>=0){
        if(board[r][c]=='Q')    return false;
        c--;
    }

    r=row,c=col;
    // bottom left column
    while(r<n && c>=0){
        if(board[r][c]=='Q')    return false;
        r++;
        c--;
    }
    
    return true;
}


void findPos(int col,int n,vector<string> &board,vector<vector<string>> &ans){
    
    if(col==n){         // reached end of the chess board
        ans.emplace_back(board);
        return;
    }
    /*
    we place queens col wise.
    for each column we place the queen every safe place
    row by row, after placing we check for next column
    when that call over we remove queen and place it in next 
    row this goes on.
    */
    for(int row=0;row<n;row++){
        if(isSafe(row,col,n,board)){
            board[row][col] = 'Q';      // place the queen
            findPos(col+1,n,board,ans); // find safe place to next col
            board[row][col] = '.';      // remove the queen
        }
    }

}
void findPosOptimized(int col,int n,vector<string> &board,
        vector<int> &leftRow, vector<int> &upperD,
        vector<int> &lowerD,vector<vector<string>> &ans){

    if(col==n){         // reached end of the chess board
        ans.emplace_back(board);
        return;
    }
    /* 
    pattern by adding indexes for each cell
    max sum is 2*(n-1)
    lower left diagonals have same sums
    0 1 2 3
    1 2 3 4
    2 3 4 5
    3 4 5 6

    n-1 + col-row for each cell
    upper left diagonals have same sums
    3 4 5 6
    2 3 4 5
    1 2 3 4
    0 1 2 3
    */
   for(int row=0;row<n;row++){
       if(leftRow[row]==0 && lowerD[row+col]==0 &&
            upperD[n-1+col-row]==0){
            
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerD[row+col] = 1;
            upperD[n-1+col-row] = 1;
            findPosOptimized(col+1,n,board,leftRow,upperD,lowerD,ans);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerD[row+col] = 0;
            upperD[n-1+col-row] = 0;
        }
   }

}
int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<string> board(n);
    string s(n,'.');
    vector<vector<string>> ans;
    vector<int> leftRow(n,0), upperD(2*n-1,0), lowerD(2*n-1,0);
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    // findPos(0,n,board,ans);

    findPosOptimized(0,n,board,leftRow,upperD,lowerD,ans);
    for(auto b:ans){
        for(auto row:b){
            cout<<row<<nl;
        }
        cout<<nl;
    }
    return 0;
}
/*
Output:
4
..Q.
Q...
...Q
.Q..

.Q..
...Q
Q...
..Q.
*/ 
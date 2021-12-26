// nxn chess board
// n queens should be placed such that no queen attacks other queen
#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row, int col, int n, vector<vector<int>> &board, vector<int> &rowQ){

    // since we placing queen left column to right column, we don't check right side of board
    // current cell column always contains single queen
    // since we're removing the queen after function call

    int r=row, c=col;
    while(r>=0 && c>=0){                // checks left upside diagonal

        if(board[r][c]==1)
            return false;
        r--;
        c--;
    }

    r=row;
    c=col;        
    while(r<n && c>=0){                 // checks left down diagonal

        if(board[r][c]==1)
            return false;
        r++;
        c--;
    }
    /*
    c=col;
    r=row;
    while(c>=0){                        // checks left side of cell in current row

        if(board[r][c]==1)
            return false;
        c--;
    }
    */
   if(rowQ[row]==1)                     // checks if there's any queen in the current row
        return false;   

    return true;                        // no way queens can attack each other
}
bool NQueen(int col,int n, vector<vector<int>> &board, vector<int> rowQ){

    if(col==n){             // filled all columns of board

        for(auto vec:board){
            for(auto e:vec)
                cout<<e<<" ";
            cout<<endl;
        }
        return true;
    }

    for(int row=0; row<n;row++){       // we'll check row wise in each column to put queen
        
        if(isSafe(row,col,n,board,rowQ)==true){      // if placing the nqueen in current row is safe

            board[row][col] = 1;            // place the queen 
            rowQ[row] = 1;                    // row has a queen

            if(NQueen(col+1,n,board,rowQ)==true)   // go for filling next column 
                return true;                // if we found answer return true, no further calls needed

            board[row][col] = 0;            // remove the queen
            rowQ[row] = 0;                  // row don't have queen

        }

    }

    return false;               // if answer not found by placing in any row in the column
}
int32_t main() {

    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<int> rowQ(n,0);          
    cout<<"Chess Board with N Queens:\n";
    if(NQueen(0,n,board,rowQ)==false)
        cout<<"Not Possible";
    return 0;
}
/*
Output:
5
Chess Board with N Queens:
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
*/
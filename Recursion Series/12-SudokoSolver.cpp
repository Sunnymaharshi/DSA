#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/*
we fill every cell row wise.
this code is not exactly as in the video.
*/
bool isValid(int row,int col,char c, vector<vector<char>> &board){

    /*
    row wise and col wise there are three 3x3 sub squares
    get the first cell of sub square in which current cell resides
    */
    int r1,c1;          // sub square first cell indexes
    r1 = 3 * (row/3);   
    c1 = 3 * (col/3);

    for(int i=0;i<9;i++){

        if(board[i][col]==c)      // check column of the cell
            return false;
        
        if(board[row][i]==c)      // check row of the cell
            return false;

        // check the cells in sub square
        // dry run these indexes
        int row = r1 + i/3;         // move across rows
        int col = c1 + i%3;         // move across columns
        if(board[row][col]==c)
            return false;

    } 
    /* if u don't understand checking sub square
       we have 1st cell index of subsquare,
       we can traverse the sub square with another loop */ 
    /*
    for(int i=r1; i<r1+3; i++){

        for(int j=c1; j<c1+3; j++){

            if(board[i][j]==c)
                return false;
        }
    }   
    */
    
    return true;

}
bool solve(int row,int col,vector<vector<char>> &board){
    if(row==9){         // filled all rows
        return true;
    }

    if(col==9){         // reached end of current row
        return solve(row+1,0,board);   // check next row 1st cell
    }

    if(board[row][col]!='.'){   // it is already filled
        // check next cell in the row
        return solve(row,col+1,board); 
    }

    for(char c='1';c<='9';c++){

        if(isValid(row,col,c,board)==true){

            board[row][col] = c;    // place the number in cell
            // check the next cell in the row
            if(solve(row,col+1,board)==true){ 
                // if we found one, we don't need to check further  
                return true;
            }
            else{                   // not possible                
                board[row][col] = '.';  // remove the number
            }

        }      
    }
    // not possible with any of the number
    return false;

}
int32_t main() {
    fastio();

    vector<vector<char>> board(9,vector<char>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    solve(0,0,board);
    for(auto row:board){
        for(auto cell:row){
            cout<<cell<<sp;
        }
        cout<<nl;
    }

    return 0;
}
/*
Output:
5 3 . . 7 . . . . 
6 . . 1 9 5 . . . 
. 9 8 . . . . 6 . 
8 . . . 6 . . . 3 
4 . . 8 . 3 . . 1 
7 . . . 2 . . . 6 
. 6 . . . . 2 8 . 
. . . 4 1 9 . . 5 
. . . . 8 . . 7 9
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9
*/
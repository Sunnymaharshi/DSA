// Problem Link:https://bit.ly/3KQELfy
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/* 
    both friends moves down together, they can move down,left and right diagonal
    there are 9 different moves possible when they move together.
    at particular time, both will be at same row since they start from top row and move 
    single row down together.
    row is same for both friends but columns are may different for both.
*/

int maxChocos_memo(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){

    if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())      // out of grid cases
        return (int)-1e8;           // return big negative value to ignore this path
    
    if(i==grid.size()-1){           // reached bottom row of grid

        if(j1==j2)                  // we both land at same cell, take it only once
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];      
    }
    
    if(dp[i][j1][j2]!=-1)           // already computed for these cells
        return dp[i][j1][j2];

    int maxsum = (int)-1e8, path;

    // 9 possible moves they can take together
    for(int dj1=-1;dj1<=1;dj1++){

        for(int dj2=-1;dj2<=1;dj2++){

            // add current cell chacolates
            path = 0;
            if(j1==j2)                              // both are at same cell
                path += grid[i][j1];
            else
                path += grid[i][j1] + grid[i][j2];

            path += maxChocos_memo(i+1,j1+dj1,j2+dj2,grid,dp);

            maxsum = max(maxsum,path);              // take max of all these paths
        }
    }

    return dp[i][j1][j2] = maxsum;                  // store before returning
}

int maxChocos_tabu(vector<vector<int>> &grid){

    int r=grid.size(),c=grid[0].size();
    // 3D dp since 3 variables i.e i,j1,j2 are changing 
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c)));

    for(int j1=0;j1<c;j1++){                            // base cases as in memo

        for(int j2=0;j2<c;j2++){

            if(j1==j2)                                  // both land at same cell
                dp[r-1][j1][j2] = grid[r-1][j1];
            else
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // for all cells in dp array
    for(int i=r-2;i>=0;i--){             // from 2nd last row to top row

        // for every possible positions for both friends in that row
        for(int j1=0;j1<c;j1++){

            for(int j2=0;j2<c;j2++){

                int maxsum = (int)-1e8, path;

                // 9 possible moves they can take together from this position
                for(int dj1=-1;dj1<=1;dj1++){

                    for(int dj2=-1;dj2<=1;dj2++){

                        // add current cell chacolates
                        path = 0;
                        if(j1==j2)                              // both are at same cell
                            path += grid[i][j1];
                        else
                            path += grid[i][j1] + grid[i][j2];

                        // next position must be inside the grid
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c)  
                            path += dp[i+1][j1+dj1][j2+dj2];
                        else
                            path = (int) -1e8;                  // negative value to ignore this path


                        maxsum = max(maxsum,path);              // take max of all these paths
                    }
                }

                dp[i][j1][j2] = maxsum;
            }
        }
    }

    return dp[0][0][c-1];           // max chocos from 1st row, friends at position 0 and c-1
}

int maxChocos_space_op(vector<vector<int>> &grid){

    // we're just using lower row values to find values of current row in tabulation
    int r=grid.size(),c=grid[0].size();
    // 2D array for 2 changing variables j1,j2
    vector<vector<int>> cur(c,vector<int>(c)),below(c,vector<int>(c));

    for(int j1=0;j1<c;j1++){                            // base cases as in memo

        for(int j2=0;j2<c;j2++){

            if(j1==j2)                                  // both land at same cell
                below[j1][j2] = grid[r-1][j1];
            else
                below[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

  
    for(int i=r-2;i>=0;i--){             // from 2nd last row to top row
        
        // for every possible positions for both friends in that row
        for(int j1=0;j1<c;j1++){

            for(int j2=0;j2<c;j2++){

                int maxsum = (int)-1e8, path;

                // 9 possible moves they can take together from this position
                for(int dj1=-1;dj1<=1;dj1++){

                    for(int dj2=-1;dj2<=1;dj2++){

                        // add current cell chacolates
                        path = 0;
                        if(j1==j2)                              // both are at same cell
                            path += grid[i][j1];
                        else
                            path += grid[i][j1] + grid[i][j2];

                        // next position must be inside the grid
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c)  
                            path += below[j1+dj1][j2+dj2];
                        else
                            path = (int) -1e8;                  // negative value to ignore this path


                        maxsum = max(maxsum,path);              // take max of all these paths
                    }
                }

                cur[j1][j2] = maxsum;
            }
        }

        below = cur;                        // make current row as below row
    }

    return below[0][c-1];           // max chocos from 1st row, friends at position 0 and c-1
}
int32_t main() {
    fastio();


    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }

    // vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    // cout<<maxChocos_memo(0,0,c-1,grid,dp);
    // cout<<maxChocos_tabu(grid);
    cout<<maxChocos_space_op(grid);
    return 0;
}
/*
Output:
3 4
2 3 1 2
3 4 2 2
5 6 3 5
21
*/
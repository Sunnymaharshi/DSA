//1. traverse the matrix if you find zero make entire column and row to -1 if ele is not zero
//   at the end you replace -1 with zeroes. TC-O((N+M)*(M+N)) SC-O(1)
//2. take 2 arrays to store set columns and set rows 
//   again traverse matrix is corresponding col or row is set you make ele as zero
//   TC-O(N+M) SC-O(N+M)
//3. instead of taking extra 2 arrays use matrix 1st col annd row to store set cols and rows
//   TC-O(N+M) SC-O(1)
#include<iostream>
#include<cstring> //for memset function
using namespace std;
int main(){
    int n,m,col0=1; //mat[0][0] is responsible for both cols and rows, 
    //col0 variable to check col0 set or not. value in mat[0][0] is used to check row0 is set or not
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(mat[i][0]==0) col0=0;
        for(int j=1;j<m;j++){
            if(mat[i][j]==0)
                mat[i][0]=mat[0][j]=0;            
        }
    }
    for(int i=n-1;i>=0; i--){                //we update our 1st col and row which have set values at last
        for(int j=m-1;j>=1;j--){
            if(mat[i][0]==0 or mat[0][j]==0)
                mat[i][j]=0;
        }
        if(col0==0)
            mat[i][0]=0;               //check 0th col is set or not
    }
    cout<<"matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
//2.
int main(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    int row[n],col[m];
    memset(row,0,sizeof(row)); //initialize rows and cols with 0
    memset(col,0,sizeof(col));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    cout<<"matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j])
                mat[i][j]=0;
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}*/
/*
Output:
3 3
1 2 0
1 1 3 
0 2 5
matrix:
0 0 0  
0 1 0  
0 0 0
*/
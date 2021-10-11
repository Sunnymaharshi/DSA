//r-1Cc-1 for rth row cth column 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> pt;
    for(int i=0;i<n;i++){
        vector<int> r(i+1);
        r[0]=r[i]=1;             //first and last elements are 1's
        for(int j=1;j<i;j++)
            r[j]=pt[i-1][j-1]+pt[i-1][j];  //add previous row elements
        pt.push_back(r);
    }
    cout<<"Pascals Triangle:\n";
    for(auto i:pt){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
/*
Output:
6
Pascals Triangle:      
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
*/
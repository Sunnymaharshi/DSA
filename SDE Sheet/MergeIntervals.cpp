// sort array - overlapping intervals are consecutive
#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(2,0));
    vector<vector<int>> mergedintervals;
    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1];
    }
    sort(vec.begin(),vec.end());
    vector<int> prev=vec[0];
    for(int i=1;i<n;i++){
        if(vec[i][0]<=prev[1])                
            prev[1]=max(prev[1],vec[i][1]);     //take max interval in both
        else{
            mergedintervals.push_back(prev);    //add previous interval to answer
            prev=vec[i];                        //update previous interval
        }
    }
    mergedintervals.push_back(prev); //add last interval to answer
    cout<<"Merged Intervals:\n";
    for(auto i:mergedintervals){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;

}
/*
Output:
5
1 2
2 5
3 10
6 8
12 13
Merged Intervals:
1 10
12 13
*/
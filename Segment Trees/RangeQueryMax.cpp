#include<iostream>
#include<vector>
using namespace std;
int arr[100005],seg[4*100005];
void buildSegmentTree(int index, int low, int high){
    
    if(low==high){           //leaf
        seg[index]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    buildSegmentTree(index*2+1, low, mid); //left child
    buildSegmentTree(index*2+2, mid+1, high); //right child
    seg[index]=max(seg[index*2+1],seg[index*2+2]); //parent
}
int query(int index, int low, int high, int l,int r){
    if(low>=l && high<=r)  //if range completely inside query range
        return seg[index];
    if(high<l || low>r)    //if range compltely outside query range
        return INT_MIN;
    int mid=(low+high)/2;  //if range overlaps with query range
    int left=query(2*index+1,low,mid,l,r);
    int right=query(2*index+2,mid+1,high,l,r);
    return max(left,right);  
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k; //no of queries
    buildSegmentTree(0,0,n-1);
    while(k--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
    return 0;

}
/*
Output:
5 
1 2 3 -3 -5
3
0 1
2
3 3
-3
3 4
-3
*/
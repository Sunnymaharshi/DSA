#include <iostream>
using namespace std;
int arr[100005],seg[4*100005];
void buildSegmentTree(int index, int low, int high){
    if(low==high){     //leaf
        seg[index]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    buildSegmentTree(index*2+1,low,mid);  //left child
    buildSegmentTree(index*2+2,mid+1,high); //right child
    seg[index]=seg[index*2+1]+seg[index*2+2]; //parent
}
int query(int index, int low, int high, int l, int r){
    if(low>=l && high<=r)   //if range completely lies inside query range
        return seg[index];

    if(high<l || low>r)    //if range completely lies outside query range
        return 0;
        
    int mid=(low+high)/2;   // if range overlaps with query range
    int left=query(index*2+1, low, mid, l, r);
    int right=query(index*2+2, mid+1, high, l, r);
    return left+right;
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
1 -1 2 -2 3
3
0 4
3
2 4
3
1 4
2
*/
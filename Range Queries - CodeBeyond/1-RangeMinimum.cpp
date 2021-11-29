// segment tree size 4*N at worst case
#include<iostream>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
class RangeMinSeg{          // range minimum segment tree template
    private:
    vector<int> seg;
    public:
    RangeMinSeg(int n){
        seg.resize(4*n +1);
    }
    void buildSegmentTree(int ind, int low, int high,int arr[]){        // time complexity - O(N)

        if(low==high){                  // leaf
            seg[ind]=arr[low];
            return;
        }
        int mid = (low + high)/2;
        buildSegmentTree(2*ind +1, low, mid,arr);
        buildSegmentTree(2*ind +2,mid+1,high,arr);
        seg[ind] = min(seg[2*ind +1],seg[2*ind + 2]);
    }
    int rangeMinQuery(int ind, int low,int high, int l,int r){  // time complexity - O(logN)

        if(r<low || l>high) return INT_MAX;         // no overlap

        if(low >= l && high <= r)   return seg[ind];    // completely overlap

        int mid = (low + high)/2;
        int left = rangeMinQuery(2*ind+1,low,mid,l,r);
        int right = rangeMinQuery(2*ind+2,mid+1,high,l,r);

        return min(left,right);                     // partial overlap
    }
    void pointUpdate(int ind, int low,int high, int i,int val){ 
        // time complexity - O(logN)
        if(low==high){
            seg[ind]=val;
            return;
        }

        int mid = (low+high)/2;
        if(i<=mid)
            pointUpdate(2*ind+1,low,mid,i,val);
        else
            pointUpdate(2*ind+2,mid+1,high,i,val);

        seg[ind] = min(seg[2*ind +1],seg[2*ind + 2]);       // update when u come back
    }
};



int main() {

    fastio();

    int n1;
    cin>>n1;
    int arr1[n1];
    RangeMinSeg st1(n1);
    for(int i=0;i<n1;i++) cin>>arr1[i];
    st1.buildSegmentTree(0,0,n1-1,arr1);

    int n2;
    cin>>n2;
    int arr2[n2];
    RangeMinSeg st2(n2);
    for(int i=0;i<n2;i++) cin>>arr2[i];
    st2.buildSegmentTree(0,0,n2-1,arr2);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){                // range query
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1 = st1.rangeMinQuery(0,0,n1-1,l1,r1);
            int min2 = st2.rangeMinQuery(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<nl;
        }
        else{                       // point update
            int arrNo,i,val;
            cin>>arrNo>>i>>val;
            if(arrNo==1)
                st1.pointUpdate(0,0,n1-1,i,val);
            else
                st2.pointUpdate(0,0,n2-1,i,val);
        }
    }

    return 0;
}
/*
Output:
5
1 2 0 3 -4
3
1 -1 10
3
1 1 4 0 2
2 2 2 -10
1 1 4 0 2 
-4
-10
*/
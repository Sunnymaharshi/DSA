// https://www.spoj.com/problems/INVCNT/
#include<iostream>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
class RangeSumSeg{          // range sum segment tree template
    private:
    vector<int> seg;
    public:
    RangeSumSeg(int n){
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
        seg[ind] = seg[2*ind +1]+seg[2*ind + 2];
    }
    int rangeSumQuery(int ind, int low,int high, int l,int r){  // time complexity - O(logN)

        if(r<low || l>high) return 0;         // no overlap

        if(low >= l && high <= r)   return seg[ind];    // completely overlap

        int mid = (low + high)/2;
        int left = rangeSumQuery(2*ind+1,low,mid,l,r);
        int right = rangeSumQuery(2*ind+2,mid+1,high,l,r);

        return  left+right;                     // partial overlap
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

        seg[ind] = seg[2*ind +1]+seg[2*ind + 2];       // update when u come back
    }
};

int main() {

    fastio();
    int t;
    cin>>t;
    while(t--){
        int n,maxi=-1;
        cin>>n;
        int arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxi = max(maxi,arr[i]);
        }
        maxi++;                         // for zero indexing
        int freq[maxi]={0};    
        for(int i=0;i<n;i++)    
            freq[arr[i]]++;
        

        RangeSumSeg st(maxi);
        // create another segment tree for negative numbers if input contains negative values
        st.buildSegmentTree(0,0,maxi-1,freq);
        int cnt=0;
        for(int i=0;i<n;i++){
            freq[arr[i]]--;                                   // remove arr[i]
            st.pointUpdate(0,0,maxi-1,arr[i],freq[arr[i]]);   // update segment tree
            cnt += st.rangeSumQuery(0,0,maxi-1,1,arr[i]-1);   // no of elements less than arr[i]
        }
        cout<<cnt<<nl;
    }


    return 0;
}
/*
Output:
2
3
3
1
2
5
2
3
8
6
1
2
5
*/
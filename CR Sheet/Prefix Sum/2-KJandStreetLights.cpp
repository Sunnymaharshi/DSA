/*
https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao/challenges/kj-and-street-lights/problem
Scanline Algorithm -> for range updates
*/
#include<iostream>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void update(int index,int range,int road[],int pos){
    int left = index-range;       
    int right = index+range+1;    // to discard value after the range
    // value updated on left will carry along the range when we do prefix sum
    if(left<0){
        road[0]++;
    }
    else{
        road[left]++;
    }
    if(right<=pos){               // we won't consider discarding value beyond pos
        road[right]--;
    }

}
int main() {

    fastio();
    int n,p;
    cin>>n>>p;
    int road[p+1]={0};            // since  KJ is at  0 and PS is at p, initialize all with 0

    for(int i=0;i<n;i++){
        int index,range;
        cin>>index>>range;
        update(index,range,road,p);
    }

    for(int i=1;i<=p;i++){              // prefix sum
        road[i] = road[i] + road[i-1];
    }

    int maxContinuousDark=0,count=0;
    for(auto i :road){
        
        if(i!=1){    // 0 means dark, >1 means light is self destructed due to light coming from more than 1 street lights

            count++;
        }
        else{         // 1 which means light coming from single street light
            count=0;  // break the continuity of dark
        }
        maxContinuousDark = max(maxContinuousDark,count);
    }
    cout<<maxContinuousDark;


    return 0;
}
/*
Output:
4 4
1 2
3 0
0 2
3 0
5
*/

/*
#python solution
n,p = map(int,input().split())
st = [0 for i in range(p+1)]
def update(i,ra):
    l=i-ra
    r=i+ra+1
    if l<0:
        st[0] +=1
    elif(l<=p):
        st[l] +=1
    if r<=p:
        st[r]-=1
        
# in test case 18, they gave n 10000 but only 9999 were given, that's why it's giving run time error
# so use try except to handle run time error
for i in range(n):
    try:
        pos,ra=map(int,input().split())
        update(pos,ra)
    except:
        pass
    
for i in range(1,p+1):
    st[i] = st[i] + st[i-1]
ans =0
d=0
for i in st:
    if i!=1:
        d+=1
    else:
        d=0
    ans=max(ans,d)
print(ans)
*/
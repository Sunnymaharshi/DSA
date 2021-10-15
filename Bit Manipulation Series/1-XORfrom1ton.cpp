/*
naive solution using loop O(N) 
n   xor val
1   1
2   3
3   0
4   4
5   1
6   7
7   0
8   4
pattern
n%4==0 --> ans=n
n%4==1 --> ans=1
n%4==2 --> ans=n+1
n%4==3 --> ans=0
O(1) solution
*/
#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;
    cout<<"xor from 1 to "<<n<<":";
    if(n%4==0)
        cout<<n;
    else if(n%4==1)
        cout<<1;
    else if(n%4==2)
        cout<<n+1;
    else
        cout<<0;

    return 0;
}
/*
Output:
12
xor from 1 to 12:12
*/

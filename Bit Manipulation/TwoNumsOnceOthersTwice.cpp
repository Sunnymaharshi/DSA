/*
two integers appears once and every other integers appears twice
find two integers that appears once
res = xor of array = a^b --> a and b are integers that appear once
if res has 1 in ith position then a and b has different bits at ith position
so we split array into two lists, one with 1 at ith position other is 0 at ith position
xor of individual lists gives a and b
*/
#include<iostream>
using namespace std;

int main() {

    int n,dBitpos=0,xr=0,a=0,b=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(auto i:arr){
        xr ^= i;
    }
    while(xr&(1<<dBitpos)!=1){
        dBitpos++;
    }
    for(auto i:arr){
        if(i&(1<<dBitpos))
            a ^= i;
        else
            b ^= i;
    }
    cout<<"a: "<<a<<" b: "<<b;
    return 0;   
}
/*
Output:
6
1 2 3 6 1 2
a: 3 b: 6
*/
//1. hashing-storing frequency of every no -->TC-O(n) SC-O(n)
/*
2.
sum of 1 to n - sum of array elements gives mis-rep
sum of squares of 1 to n - sum of squares of array elements gives mis^2-rep^2
find mis,rep from 2 eqs 
x-y=a
x^2-y^2=b
x+y=b/a
x=(a+b/a)/2
y=x-a
*/
/*
3.
xor of all no's in array and 1-n which is equal to mis^rep no's
separate array elements into two buckets using above set index
divide 1-n no's and put into those buckets according to set index 
one will present in array which is repeating no other is missing  no */
#include<iostream>
using namespace std;
int  main(){
    int n,xorarr=0,b1=0,b2=0,setind,ch=0,mis,rep;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        xorarr^=arr[i];
    }
    setind=0;
    while(xorarr && !((xorarr>>setind)&1)){
        setind++;                                    // find index of set bit
    }
    //cout<<setind<<"set ind";
    for(int i=1;i<=n;i++){
        if((i>>setind)&1){
            b1^=i;                                   // 1-n no's whose setind is set xor with b1
        }
        else
            b2^=i;                                   // 1-n no's whose setind is not set xor with b2
    }
    for(int i=0;i<n;i++){
        if((arr[i]>>setind)&1){                      // array ele whose setind is set xor with b1
            b1^=arr[i];
        }
        else
            b2^=arr[i];                              // array ele whose setind is not set xor with b2
    }
    for(int i=0;i<n;i++){
        if(b1==arr[i]){                              // find whether b1 is repeating or missing no
            ch=1;
            break;
        }
    }
    if(ch){
        rep=b1;
        mis=b2;
    }
    else{
        rep=b2;
        mis=b1;
    }
    cout<<"Missing no:"<<mis<<" Repeating no:"<<rep<<endl;
    
    return 0;
}
/*
2.
int main(){
    long n,sumofn,sumofarr=0,sumofqn,sumofqarr=0,a,b,mis,rep;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sumofarr+=arr[i];
        sumofqarr+=arr[i]*arr[i];
    }
    sumofn=(n*(n+1))/2;
    sumofqn=n*(n+1)*(2*n+1)/6;
    a=sumofn-sumofarr;
    b=sumofqn-sumofqarr;
    mis=(a+b/a)/2;
    rep=mis-a;
    cout<<"Missing no:"<<mis<<" Repeating no:"<<rep<<endl;   
    return 0;
}
*/
/*
Output:
5    
1 2 3 3 5
Missing no:4 Repeating no:3
*/
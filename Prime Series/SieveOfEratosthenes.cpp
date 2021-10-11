#include<iostream>
#include<string.h>
using namespace std;
bool sieve[1000005];
int N=1000000;
void buildSieve(){
    memset(sieve,true,sizeof(sieve));
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i*i<=N;i++){
        /*
        since inner for loop run only upto sqrt(N)
        so for i beyond sqrt(N), inner loop won't run
        hence we run above loop upto sqrt(N)
        */
        if(sieve[i]==true){
            for(int j=i*i; j<=N; j+=i){
                /*
                for i upto i-1 numbers are already marked
                by previous primes
                i.e.for 3
                3*2-->6 --> 3*2 it is marked by prime number 2 which is less than 3
                hence we start marking from i*i
                */
               sieve[j]=false;
            }
        }
    }
}
int main() {
    buildSieve();
    int T;
    cout<<"enter no of test cases:";
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(sieve[n])
            cout<<"prime\n";
        else
            cout<<"not prime\n";
    }

    return 0;
}
/*
Output:
enter no of test cases:4
16
not prime
12324
not prime
11111
not prime
23269
prime
*/
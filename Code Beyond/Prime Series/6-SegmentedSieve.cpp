#include<iostream>
#include<string.h>
#include<vector>
#include<cmath>
using namespace std;
/* 
T(test cases)<=10
(L,R)<=10^12 
R-L<=10^6
we can not create array of size 10^12, so we can't use sieve method.
Segmented Sieve:
All primes under maxrange(10^9) are <= sqrt(maxrange) i.e 10^6.
considering worst case, we build sieve array of size 10^6 to find primes.
we find all primes less than r and remove those multiples in given range.
*/
bool sieve[1000005];
int N=1000000;
void buildSieve(){
    memset(sieve,true,sizeof(sieve)); // initialize everything with 1
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i*i<=N;i++){
        if(sieve[i]==true){
            for(int j=i*i; j<=N; j+=i){
               sieve[j]=false;
            }
        }
    }
}
vector<int> generatePrimes(int r){
    vector<int> primes;
    for(int i=2;i<=r;i++){
        if(sieve[i]==true)
            primes.emplace_back(i);
    }
    return primes;
}
int main() {

    //O(10^6)
    buildSieve();
    int T;
    cout<<"enter no of test cases:";
    cin>>T;
    while(T--){
        int l,r;
        cin>>l>>r;
        // we only need primes upto sqrt of r.
        // since in sieve, a prime p starts marking from p*p
        // O(10^6)
        vector<int> primes=generatePrimes(sqrt(r));

        // create dummy array of size R-L+1 initialize with true
        // O(10^6)
        bool dSieve[r-l+1];
        memset(dSieve,true, sizeof(dSieve));
         
        // mark all multiples of primes in dummy array as false
        // at max O(10^4)
        for(auto p: primes){

            int firstMultiple = (l/p) * p;
            if(firstMultiple<l) firstMultiple+=p;
            /* if l=32, p=3 
            firstMultiple = (32/3) * 3
            firstMultiple = 10*3 = 30
            30 not in range hence add 3
            firstMultiple = 33
            */

            for(int j=max(firstMultiple,p*p); j<=r;j+=p){
                // since some numbers are already marked by previous primes 
                // we start marking from max of firstMultiple and p*p
                dSieve[j-l]=false;
            }
        }
        // print primes
        for(int i=l; i<=r; i++){
            if(dSieve[i-l]==true)
                cout<<i<<" ";
        }
        cout<<endl;

    }

    return 0;
}

/*
Output:
enter no of test cases:2
2 50
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
50 150
53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149
*/
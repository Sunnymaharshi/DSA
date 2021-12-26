// https://www.spoj.com/problems/PRIME1/
#include<iostream>
#include<vector>
#include<string.h>
#define nl "\n"
#define int long long
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int maxrange = 1000000000LL; 
/* we can not create array of size 10^9, so we can't use sieve method.
Segmented Sieve:
all primes under maxrange(10^9) are <= sqrt(maxrange) i.e ~10^5.
considering worst case, we build sieve array of size 10^5 to find primes.
we find all primes less than r and remove those multiples in given range.
*/
bool sieve[100005];
int N = 100000;         
void buildSieve(){
    memset(sieve,true,sizeof(sieve));
    sieve[0]=sieve[1]=false;
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
    // we only need primes upto sqrt of r.
    // since in sieve, a prime p starts marking from p*p
    for(int i=2;i*i<=r;i++){        
        if(sieve[i]==true)
            primes.emplace_back(i);
    }
    return primes;
}
void solve() {
    int l, r;
    cin>>l>>r;
    vector<int> primes;
    primes = generatePrimes(r);     // all primes less than r
    // create dummy array of size R-L+1 initialize with true
    int rangelen = r-l+1;
    bool dSieve[rangelen];
    memset(dSieve,true, sizeof(dSieve));
    if(l==1)              // 1 is not prime
        dSieve[0]=false;
    

    // mark all multiples of primes in dummy array as false
    for(auto p: primes){

        int firstMultiple = (l/p) * p;
        if(firstMultiple<l) firstMultiple += p;
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
            cout<<i<<nl;
    }
    cout<<nl;   
    
}
int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    buildSieve();
    while(t--) {
        solve();
    }

    return 0;
}
/*
Output:
*/
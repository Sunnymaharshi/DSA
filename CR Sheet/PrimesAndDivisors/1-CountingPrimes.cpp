// https://www.codechef.com/problems/CNTPRIME
#include<iostream>
#include<string.h>
#include<vector>
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int maxval=10000007;
int sieve[maxval];
void buildSieve(){

    for(int i=0;i<=maxval;i++)
        sieve[i]=1;
    sieve[0]=sieve[1]=0;       // not primes

    for(int i=2;i*i<=maxval;i++){
        
        if(sieve[i]==1){
            for(int j = i*i; j <= maxval; j+=i){    // mark all its multiples        
                sieve[j] = 0;        
            }   
        }      
    }
    for(int i=1;i<=maxval;i++){         // prefix sum
        sieve[i] += sieve[i-1];
    }
}
void solve() {
    int l, r;
    cin>>l>>r;
    cout<<sieve[r]-sieve[l-1]<<nl; 
}
int main() {

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
4
2 13
3 3
3 7
4 10
6
1
3
2
*/
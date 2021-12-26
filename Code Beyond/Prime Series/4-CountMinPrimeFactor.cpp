#include<iostream>
using namespace std;
//  this is modified sieve of eratosthenes, check that before this.
//int N=1000000;
int N=10000000;
int sieve[10000001];

void buildSieve(){

    for(int i=2;i<=N;i++)
        sieve[i]=1;
    // seive[i] stores count of numbers whose minimum factor is i
    for(int i=2;i*i<=N;i++){
    
        if(sieve[i]==1){
            for(int j=i*i; j<=N; j+=i){
                
               if(sieve[j]!=0){   // if minimum factor of j not found yet i.e. i is minimum factor of j
                   sieve[i]++;  // increasing count for prime i
                   sieve[j]=0;  // marking it as 0 as we found it's minimum factor
               }
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
        cout<<sieve[n]<<endl;
    }

    return 0;
}

/*
Ouptut:
enter no of test cases:3
2
5000000
3
1666667
3137
7
*/
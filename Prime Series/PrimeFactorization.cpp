#include<iostream>
using namespace std;
//  this is modified sieve of eratosthenes, check that before this.
//int N=1000000;
int N=1000000;
int sieve[1000001];

void buildSieve(){

    for(int i=1;i<=N;i++)
        sieve[i]=i;
    

    // seive[i] stores minimum factor is i
    for(int i=2;i*i<=N;i++){
    
        if(sieve[i]==i){
            for(int j=i*i; j<=N; j+=i){
                
               if(sieve[j]==j){  // if minimum factor not found yet
                   sieve[j]=i; // update minimum factor for j
               }
            }
        }
    }
}
void printPrimeFactorsNaive(int n){   // O(sqrt(N)) for each query
    
    cout<<"Prime Factors:";
    for(int i=2; i*i<=n; i++){

        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>1)
        cout<<n;
    cout<<endl;

}
int main() {
    buildSieve();
    int T;
    cout<<"enter no of test cases:";
    cin>>T;
    
    while(T--){
        int n;
        cin>>n;
        //printPrimeFactorsNaive(n);
        cout<<"prime factors:";
        while(n!=1){         // O(logN) for each query
            cout<<sieve[n]<<" ";
            n=n/sieve[n];
        }
        cout<<endl;
    }

    return 0;
}

/*
Ouptut:
enter no of test cases:5
63
prime factors:3 3 7 
97
prime factors:97 
223
prime factors:223 
3163
prime factors:3163 
3319
prime factors:3319
*/
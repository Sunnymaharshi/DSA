// 1 and itself as factors
#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n<=1)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    if(isPrime(n)==true){
        cout<<n<<" is a prime number";
    }
    else{
        cout<<n<<" is not a prime number";
    }
    return 0;
}
/*
Output:
enter a number:13
13 is a prime number
*/
// https://cses.fi/problemset/task/2182
// couldn't find optimal & understandable solution
#include<iostream>
using namespace std;
#include<vector>
#include<cmath>
#define nl "\n"
#define int long long
int mod = 1000000007;
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
vector<int> findDivisors(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.emplace_back(i);
            if(n/i!=i){         //checking other factor is not same
                ans.emplace_back(n/i);
            }
        }
    }
    return ans;
}
void solve() {
    int f,n=1LL;
    cin>>f;
    while(f--){
        int prime,p;
        cin>>prime>>p;
        n *= pow(prime,p);
    }
    vector<int> divisors;
    divisors=findDivisors(n);
    int mul=1LL,add=0LL;
    for(auto i:divisors){
        mul = ((mul%mod)*(i%mod))%mod;
        add = ((add%mod)+(i%mod))%mod;
    }
    cout<<divisors.size()<<" "<<add<<" "<<mul;

}
int32_t main() {
    fastio();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
/*
Output:
*/
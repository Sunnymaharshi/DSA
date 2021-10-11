#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> factors(int n){
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
int main() {
    vector<int> res;
    int n;
    cout<<"enter a number:";
    cin>>n;
    res=factors(n);
    sort(res.begin(),res.end()); //sorting factors
    for(auto i: res){
        cout<<i<<" ";
    }

return 0;
}

/*
Output:
enter a number:24
1 2 3 4 6 8 12 24
*/
/* https://codeforces.com/problemset/problem/1354/B
min len is 3 
max len is len(string)
range 3 to len(string)
*/
#include<iostream>
#include<vector>
using namespace std;
bool isValid(string s, int k){
    int arr[3]={0};
    for(int i=0;i<k;i++){
        arr[s[i]-'1']++;
    }
    if(arr[0]>0 && arr[1]>0 && arr[2]>0)
        return true;
    int l=0,r=k;
    while(r!=s.size()){             // sliding window
        arr[s[r]-'1']++;
        r++;
        arr[s[l]-'1']--;
        l++;
        if(arr[0]>0 && arr[1]>0 && arr[2]>0)
            return true;
    }
    return false;
}

int findMinLength(string s){

    int low=3, high =s.size();
    int ans=0;
    while(low<=high){

        int mid = low + (high-low)/2;
        if(isValid(s,mid)){
            ans=mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;

}
int twoPointerApproach(string s){
    int arr[3]={0};
    int l=0,r=0,ans=s.size() +1;
    while(r!=s.size()){
        arr[s[r]-'1']++;
        while(arr[0]>0 && arr[1]>0 && arr[2]>0){    // if valid, shrink size
            ans = min(ans,r-l+1);
            arr[s[l]-'1']--;
            l++;
        }
        r++;                                        // else increase size
    }
    if(ans==s.size()+1){
        ans=0;
    }
    return ans;
}
int main() {
    int T;
    vector<string> ss;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        ss.emplace_back(s);
    }
    for(auto s: ss)
        cout<<"min len of "<<s<<":"<<findMinLength(s)<<endl;
    
    return 0;
}
/*
Output:
7
123
12222133333332
112233
332211
12121212
333333
31121
min len of 123:3
min len of 12222133333332:3
min len of 112233:4
min len of 332211:4
min len of 12121212:0
min len of 333333:0
min len of 31121:4
*/
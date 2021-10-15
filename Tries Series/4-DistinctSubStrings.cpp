// if we use set to store distinct substrings Space Complexity is O(N^3)
#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    Node* arr[26];
    bool flag=false;
    bool contains(char ch){

        return (arr[ch-'a'] != NULL);
    }
    void put(char ch, Node* node){
        arr[ch-'a'] = node;
    }
    Node* getNext(char ch){
        return arr[ch-'a'];
    }
    void setFlag(){
        flag = true;
    }
    bool isFlagSet(){
        return flag;
    }

};
Node* root = new Node();
vector<string> distinctSubstrings(string s){
    int count=0; //no of distinct substrings
    vector<string> ds;
    for(int i=0;i<s.size();i++){
        
        Node* temp=root;
        string ss="";
        for(int j=i;j<s.size();j++){

            if(!temp->contains(s[j])){
                Node* newNode = new Node();
                temp->put(s[j],newNode);
                temp = temp->getNext(s[j]);
                temp->setFlag();
                ss+=s[j];
                ds.emplace_back(ss);
                count++;
            }
            else{
                temp = temp->getNext(s[j]);
                ss+=s[j];
            }
        }
    }

    return ds;
    
}

int main() {


    string s;
    cout<<"enter a string:";
    cin>>s;
    cout<<"distinct substrings:";
    vector<string> ans=distinctSubstrings(s);
    for(auto ss:ans)
        cout<<ss<<" ";
    return 0;
}
/*
Output:
enter a string:maa
distinct substrings:m ma maa a aa 
*/
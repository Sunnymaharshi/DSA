#include<iostream>
#include<vector>
#include<algorithm>
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
int insert(string word){
    Node* temp=root;
    int flags=0;
    for(int i=0;i<word.size();i++){
        
        if(!temp->contains(word[i])){
            Node* newNode = new Node();
            temp->put(word[i],newNode);
        }
        temp = temp->getNext(word[i]);
        if(temp->isFlagSet()) flags++;
    }
    temp->setFlag();
    return flags;
}
string longestWord(vector<string> words){

    sort(words.begin(),words.end());
    string res="";
    int maxFlags=0;
    for(auto word : words){
        int flags= insert(word);
        if(flags==word.size()-1 && word.size()>res.size()){ 
            //if we have all prefixes and longer word
            res=word;   
        }

    }
    return res;

}
int main() {
    int W;
    cin>>W;
    string word;
    vector<string> words;

    while(W--){
        cin>>word;
        words.emplace_back(word);
    }
    cout<<"longest word with all prefixes:"<<longestWord(words);

    return 0;
}
/*
7
a
banana
app
appl
ap
apply
apple
longest word with all prefixes:apple
*/
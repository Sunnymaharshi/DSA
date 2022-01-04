// Problem Link: https://bit.ly/3ocRQW0
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct Node {

    Node *links[26];        // stores the links or references to 26 alphabets
    bool end=false;         // to check if any word ends here

    bool hasLetter(char letter){

        return links[letter-'a']!=NULL;  // returns true if node has letter
    }
    void putLetter(char letter,Node* node){

        links[letter-'a'] = node;
    }
    Node* getNode(char letter){
        
        return links[letter-'a'];
    }

};
int uniqueSubstrings(string word){

    /*
        add letter by letter
        each time we added a new letter, 
        we increase count since string upto that letter
        is a substring.
    */
    int count=0;
    Node* root = new Node();                // initialize trie

    for(int i=0;i<word.length();i++){

        Node* node = root;
        // adding all substrings starting with word[i]

        for(int j=i;j<word.length();j++){

            if(!node->hasLetter(word[j])){
                
                // new letter is added into trie
                node->putLetter(word[j],new Node()); 
                
                count++;     // string upto current letter is new substring
            }

            node = node->getNode(word[j]);  // move to current letter
        }          
    }
    return count;
}
int32_t main() {

    fastio();    
    string word;
    cin>>word;
    cout<<uniqueSubstrings(word)+1;         // unique substrings and empty string    
    return 0;
}
/*
Output:
aab
6
*/
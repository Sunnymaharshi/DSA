/*
Problem Link: https://bit.ly/3n3kedU
longest word with all it's prefixes present
Time Complexity - O(N*len+N*len) n is no of words and 
len is average length of words, one is for inserting and 
other is for checking
*/
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

    void setEnd(){

        end = true;
    }

    bool isEnd(){

        return end;
    }
};

class Trie
{

private:
    Node* root;

public:

    // constructor to initialize when trie is created
    Trie(){

        root = new Node();      // initialize root

    }

    void insert(string word){

        Node* node = root;         // take reference of root to traverse the trie

        for(int i=0;i<word.length();i++){

            if(!node->hasLetter(word[i])){     // if node doesn't have the letter
                
                // create node and add it in place of letter
                node->putLetter(word[i],new Node()); 
            }

            node = node->getNode(word[i]);             // move to current letter             
        }

        // last letter points to current node
        node->setEnd();                         // word is ended at this letter

    }

    bool isAllPrefixesExists(string word){

        Node* node = root;

        for(int i=0;i<word.length();i++){

            if(node->hasLetter(word[i])){
                
                node = node->getNode(word[i]);         // move to this letter

                if(node->isEnd()==false){       // prefix upto this letter does not exist
                    return false;   
                }  
            }
            else{                               // word does not exists
                return false;
            }
        }
        return true;                // word and all its prefixes exists

    }
};
string longestCompleteString(vector<string> &words){

    Trie trie;
    for(auto word:words){           // insert all words into trie

        trie.insert(word);  
    }
    string longestWord = "";
    for(auto word:words){

        if(trie.isAllPrefixesExists(word)){

            if(word.length()>longestWord.length()){

                longestWord = word;
            }
            else if(word.length()==longestWord.length() && word<longestWord){   

                // if lenghts are same, take lexicographically smaller one
                longestWord = word;
            }
        }
    }


    if(longestWord=="")
        return "None";

    return longestWord;

}

int32_t main() {
    fastio();
    int n;
    cin>>n;
    vector<string> words(n,"");
    for(int i=0;i<n;i++)    cin>>words[i];

    cout<<longestCompleteString(words);

    return 0;
}
/*
Output:
4
a
ab
abc
aba
aba
*/
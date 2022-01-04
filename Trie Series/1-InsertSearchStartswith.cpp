// Problem Link: https://bit.ly/3n4m3Hu
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

    bool search(string word){

        Node* node = root;         // take reference of root to traverse trie

        for(int i=0;i<word.length();i++){

            if(!node->hasLetter(word[i])){
                return false;          // letter not exist, then word not exist                
            }
            
            node = node->getNode(word[i]);    // move the node to current letter
        }

        // last letter points to current node
        // if end of current node is true, then word exists
        node->isEnd();


    }

    bool startsWith(string prefix){

        Node* node = root;         // take reference of root to traverse trie

        for(int i=0;i<prefix.length();i++){

            if(!node->hasLetter(prefix[i])){
                return false;          // letter not exist, then prefix not exist                
            }
            
            node = node->getNode(prefix[i]);    // move the node to current letter
        }

        // no need to check if there is end at last letter
        // since we are checking for prefixes, we only need to check
        // if all the letter exists in the trie or not
        return true;

    }
    
};

int32_t main() {
    fastio();

    return 0;
}
/*
Output:
*/
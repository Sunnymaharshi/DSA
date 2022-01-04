// Problem Link: https://bit.ly/3qwT4OL
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct Node {

    Node *links[26];        // stores the links or references to 26 alphabets
    int cntPrefixes = 0;    // count prefixes
    int endsWith = 0;       // count words ending here


    bool hasLetter(char letter){

        return links[letter-'a']!=NULL;  // returns true if node has letter
    }

    void putLetter(char letter,Node* node){

        links[letter-'a'] = node;
    }

    Node* getNode(char letter){

        return links[letter-'a'];
    }

    void increaseEnd(){
        endsWith++;
    }
    void increasePrefixes(){        
        cntPrefixes++;
    }

    bool reduceEnd(){
        endsWith--;   
    }
    bool reducePrefixes(){
        cntPrefixes--;   
    }

    int getEnd(){
        return endsWith;
    }

    int getPrefixes(){
        return cntPrefixes;
    }
};

class Trie {

    private: Node* root;
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
            node->increasePrefixes();           // increase count of prefixes
        }

        // last letter points to current node
        node->increaseEnd();                         // increase end i.e no of words ends here

    }

    int countWordsEqualTo(string word){

        Node* node = root;         // take reference of root to traverse trie

        for(int i=0;i<word.length();i++){

            if(!node->hasLetter(word[i])){
                return 0;          // letter not exist, then word not exist                
            }
            
            node = node->getNode(word[i]);    // move the node to current letter
        }

        // last letter points to current node
        // endsWith contains no of words ending with this last letter of word
        return node->getEnd();

    }

    int countWordsStartsWith(string prefix){

        Node* node = root;         // take reference of root to traverse trie

        for(int i=0;i<prefix.length();i++){

            if(!node->hasLetter(prefix[i])){
                return 0;          // letter not exist, then prefix not exist                
            }
            
            node = node->getNode(prefix[i]);    // move the node to current letter
        }

        // no need to check if there is end at last letter
        // since we are checking for prefixes, we only need to check
        // if all the letter exists in the trie or not
        // cntPrefixes stores no of prefixes ending here
        return node->getPrefixes();
    }

    void erase(string word){

        Node* node = root;         // take reference of root to traverse trie      
        
        for(int i=0;i<word.length();i++){

            if(node->hasLetter(word[i])){
                node = node->getNode(word[i]);     // move the node to current letter
                node->reducePrefixes();     // since this prefix part of this word
            }
            else                            // word does not exists
                return;          
        }

        // last letter points to current node
        // reduce endsWith i.e no of words ending with this last letter of word
        node->reduceEnd();        
    }



};
int32_t main() {
    fastio();

    return 0;
}
/*
Output:
*/
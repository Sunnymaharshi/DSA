#include<iostream>
using namespace std;
// node which last char points, contains word and prefix counts.
struct Node
{
    Node* arr[26];
    int countWords=0;
    int countPrefixes=0;

    bool contains(char ch){

        return (arr[ch-'a'] != NULL);
    }
    void put(char ch, Node* node){
        arr[ch-'a'] = node;
    }
    Node* getNext(char ch){
        return arr[ch-'a'];
    }
    void increaseWords(){
        countWords++;
    }
    void increasePrefixes(){
        countPrefixes++;
    }
    int getWordsCount(){
        return countWords;
    }
    int getPrefixCount(){
        return countPrefixes;
    }
    void decreaseWords(){
        countWords--;
    }
    void decreasePrefixes(){
        countPrefixes--;
    }

};
Node* root = new Node();
void insert(string word){
    Node* temp=root;
    for(int i=0;i<word.size();i++){
        
        if(!temp->contains(word[i])){
            Node* newNode = new Node();
            temp->put(word[i],newNode);
        }
        temp = temp->getNext(word[i]);
        temp->increasePrefixes();
    }
    temp->increaseWords();
}
int countWordsEqualTo(string word){
    Node* temp = root;
    for(int i=0; i<word.size(); i++){
        if(temp->contains(word[i]))
            temp = temp->getNext(word[i]);
        else
            return 0;
    }
    return temp->getWordsCount();
}
int countWordsStartsWith(string word){

    Node* temp = root;
    for(int i=0; i<word.size(); i++){
        if(temp->contains(word[i]))
            temp = temp->getNext(word[i]);
        else
            return 0;
    }
    return temp->getPrefixCount();
}
void erase(string word){

    if(countWordsEqualTo(word)==0) return;
    Node* temp = root;
    for(int i=0; i<word.size(); i++){
        temp = temp->getNext(word[i]);       
        temp->decreasePrefixes();
    }
    temp->decreaseWords();

}
int main() {
    int choice;
    string word;
    cout<<"1 for counting words\n2 for counting words that starts With\n3 for insert\n4 for erase\n0 for exit\n";
    while(1){
        cout<<"choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cin>>word;
            cout<<"word count:"<<countWordsEqualTo(word)<<endl;
            break;
        case 2:
            cin>>word;
            cout<<"prefix count:"<<countWordsStartsWith(word)<<endl;
            break;
        case 3:
            cin>>word;
            insert(word);
            cout<<"word inserted\n";
            break;
        case 4:
            cin>>word;
            erase(word);
            cout<<"word erased\n";
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }

    }


    return 0;
}   
/*
Output:
1 for counting words
2 for counting words that starts With
3 for insert
4 for erase
0 for exit
choice:3
maharshi
word inserted
choice:3
maharsh
word inserted
choice:1
maharshi
word count:1
choice:2
maharsh
prefix count:2
choice:4
maharsh
word erased
choice:2
maharsh
prefix count:1
choice:0
*/
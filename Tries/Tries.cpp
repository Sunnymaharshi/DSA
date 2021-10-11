#include<iostream>
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
void insert(string word){
    Node* temp=root;
    for(int i=0;i<word.size();i++){
        
        if(!temp->contains(word[i])){
            Node* newNode = new Node();
            temp->put(word[i],newNode);
        }
        temp = temp->getNext(word[i]);
    }
    temp->setFlag(); // last character of word points to node with flag is true.
}
bool search(string word){
    Node* temp = root;
    for(int i=0; i<word.size(); i++){
        if(temp->contains(word[i]))
            temp = temp->getNext(word[i]);
        else
            return false;
    }
    return temp->isFlagSet();
}
bool startsWith(string word){

    Node* temp = root;
    for(int i=0; i<word.size(); i++){
        if(temp->contains(word[i]))
            temp = temp->getNext(word[i]);
        else
            return false;
    }
    return true;
}
int main() {
    int choice;
    string word;
    cout<<"1 for search\n2 for startsWith\n3 for insert\n0 for exit\n";
    while(1){
        cin>>choice;
        switch (choice)
        {
        case 1:
            cin>>word;
            if(search(word))
                cout<<"found\n";
            else
                cout<<"not found\n";
            break;
        case 2:
            cin>>word;
            if(startsWith(word))
                cout<<"found\n";
            else    
                cout<<"not found\n";
            break;
        case 3:
            cin>>word;
            insert(word);
            cout<<"word inserted\n";
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
1 for search    
2 for startsWith
3 for insert    
0 for exit      
3
maharshi
word inserted
1
maharshi
found
2   
maha
found
1
sunny
not found
0
*/
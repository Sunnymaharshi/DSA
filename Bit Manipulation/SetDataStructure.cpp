// no of elements should be less than 64
// add remove in O(1)
// space complexity - O(1)
#include<iostream>
#include<vector>
using namespace std;
long long ds = 0LL;
void print(){
    for(int bit=0; bit<=63; bit++){
        if(ds & (1LL<<bit))
            cout<<bit+1<<" ";
    }
    cout<<endl;
}
void add(int n){
    if(n<64){
        ds = ds | (1LL<<(n-1)); // set (n-1)th bit
        cout<<"added\n";
    }
    else
        cout<<"cannot add\n";
}
void remove(int n){
    if(n<64){
        ds = ds&(~(1LL<<(n-1))); // clear (n-1)th bit
        cout<<"removed\n";
    }
    else
        cout<<"doesn't exists!\n";
}
int main() {
    int choice,n;
    cout<<"1:add\n2:remove\n3:print\n4:exit\n";
    while(true){
        cout<<"choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter number less than 64:";
            cin>>n;
            add(n);
            break;
        case 2:
            cout<<"enter number less than 64:";
            cin>>n;
            remove(n);
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
            break;
        
        default:
            exit(0);
            break;
        }
    }

    return 0;
}

/*
Output:
1:add
2:remove
3:print
4:exit
choice:1
enter number less than 64:56
added
choice:1
enter number less than 64:33
added
choice:1
enter number less than 64:3
added
choice:3
3 33 56 
choice:2
enter number less than 64:56
removed
choice:3
3 33 
choice:4
*/
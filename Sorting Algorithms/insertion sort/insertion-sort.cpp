#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,key;
    cin>>n;  
    int arr[n];
    
    for(i=0;i<n;i++) cin>>arr[i]; 

    for(j=1;j<n;j++){ //starting from 2nd element
        key=arr[j];    
        i=j-1;
        while(i>=0 && arr[i]>key){  
            arr[i+1]=arr[i]; //moving forward all elements left  of key 
                            //which are  greater than key
            i=i-1;
        }
        arr[i+1]=key;    //inserting key before elements greater than it
    }

    for(i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;

}
/*
6
5 2 4 6 1 3
1 2 3 4 5 6 
*/
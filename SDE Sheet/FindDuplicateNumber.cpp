//1. sort array and check adjacent elements if it is repeated or not TC-O(NlogN)
//2. hashing - count frequency of  elements by maintaining frequency array TC-O(N) SC-O(N)
//3. Tortoise-Hare method - checks if there is a cycle or not
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int slow,fast;
    slow=fast=nums[0];
    do{
        slow=nums[slow];          //moves 1 step
        fast=nums[nums[fast]];    //moves 2 steps
    }while(slow!=fast);           //if slow=fast there exists a cycle
    fast=nums[0];
    while(slow!=fast){           //move both 1 step at a time until they are equal
        slow=nums[slow];
        fast=nums[fast];         
    }                           
    //they meet at duplicate number
    cout<<"Duplicate number:"<<slow;
    return 0;
}
/*
Output:
5
1 2 3 3 4
Duplicate number:3
*/
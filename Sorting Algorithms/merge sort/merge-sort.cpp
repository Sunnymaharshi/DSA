#include<bits/stdc++.h>
using namespace std;
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w", stdout);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;



}
void  merge_sort(int arr[],int left, int right){
    if(left<right){
        int mid;
        mid=(left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    else{
        return;
    }
}
void merge(int arr[], int left, int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int i,j,k;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+i+1];
    }
    k=left;
    i=j=0;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }

}
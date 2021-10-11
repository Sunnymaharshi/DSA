#include <bits/stdc++.h>
using namespace std;
void mergeSort(int arr[],int l,int r);
void merge(int arr[],int l,int m,int r);
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w", stdout);
#endif
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) 
		cin>>arr[i];
	mergeSort(arr,0,n-1);
	for(auto i:arr) 
		cout<<i<<" ";
	return 0;
}
void mergeSort(int arr[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}

}
void merge(int arr[],int l,int m, int r){
	int n1=m-l+1,n2=r-m;
	int a[n1],b[n2];
	for(int i=0;i<n1;i++){
		a[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++){
		b[i]=arr[m+1+i];
	}
	int k=l,i=0,j=0;

	while(i<n1 && j<n2){
		if(a[i]<=b[j]){
			arr[k]=a[i];
			i++;
		}
		else{
			arr[k]=b[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=a[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=b[j];
		j++;
		k++;
	}
}
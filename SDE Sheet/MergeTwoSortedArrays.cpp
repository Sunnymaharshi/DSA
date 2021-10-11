//1. using extra space SC-O(n+m) TC-O(n+m)
//2. swap elements and sort unsorted array
//3. gap method
#include<iostream>
#include<cmath>
using namespace std;
int nextGap(int g){
    if(g<=1)
        return 0;
    
    return ceil(g/2);
}
int main()
{
    int n,m,gap;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    gap=nextGap(n+m);
    while(gap>0){
        int i,j;
        //process 1st array
        for(i=0;i+gap<n;i++){
            if(a[i]>a[i+gap])
                swap(a[i],a[i+gap]);
        }
        // process both arrays
        j=gap>n ? gap-n : 0; 
        //if gap greater than n above loop won't execute
        //we start from (gap-n)th index of element
        //else we start from where above loop ends
        while(i<n && j<m){
            if(a[i]>b[j])
                swap(a[i],b[j]);
            i++;
            j++;
        }
        //process 2nd array
        for(j=0; j+gap<m;j++){
            if(b[j]>b[j+gap])
                swap(b[j],b[j+gap]);
        }
        gap=nextGap(gap);

    }
    cout<<"a:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\nb:";
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
    
}
/*
2.
int main(){
    int n,m,i=0,j=0;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    while(i<n){
        if(a[i]>b[j]){
            swap(a[i],b[j]);
            // insertion sort to sort b array
            int i, key, j;
            for (i = 1; i < m; i++)
            {
                key = b[i];
                j = i - 1;
                while (j >= 0 && b[j] > key)
                {
                    b[j + 1] = b[j];
                    j = j - 1;
                }
                b[j + 1] = key;
            }
        }
        i++;
    }
    cout<<"a:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\nb:";
    for(int i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    return 0;


}*/
/*
Output:
5 3
1 5 6 10 15 2 3 9
a:1 2 3 5 6 
b:9 10 15
*/
def merge(arr,left,mid,right):
    n1=mid-left+1
    n2=right-mid
    L=[arr[left+x] for x in range(n1)]
    R=[arr[mid+x+1] for x  in range(n2)]
    k=left
    i=j=0
    while(i<n1 and j<n2):
        if(L[i]<=R[j]):
            arr[k]=L[i]
            i=i+1
        else:
            arr[k]=R[j]
            j=j+1
        k=k+1
    while(i<n1):
        arr[k]=L[i]
        i+=1
        k+=1
    while(j<n2):
        arr[k]=R[j]
        j+=1
        k+=1
def merge_sort(arr,left,right):
    if left<right:
        mid=(left+right)//2
        merge_sort(arr,left,mid)
        merge_sort(arr,mid+1,right)
        merge(arr,left,mid,right)

n=int(input())
arr=list(map(int,input().split()))
merge_sort(arr,0,n-1)
print(*arr)
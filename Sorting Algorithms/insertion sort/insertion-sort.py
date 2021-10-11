n=int(input())
arr=list(map(int,input().split()))

for j in range(1,n): #starting from 2nd element
    key=arr[j]      
    i=j-1

    while i>=0 and arr[i]>key :
        arr[i+1]=arr[i] #moving forward all elements left of key
                    #which are  greater than key
        i=i-1
    
    arr[i+1]=key   #inserting key before elements greater than it


print(*arr)        

"""
6
5 2 4 6 1 3
1 2 3 4 5 6
"""
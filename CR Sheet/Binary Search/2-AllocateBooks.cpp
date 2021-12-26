/*
https://www.interviewbit.com/problems/allocate-books/
we need to find minimum of maximum books allocated to k students
minimum possible answer is min(books)
maximum possible answer is sum(books)
range min(books) to sum(books)
*/

#include<iostream>
#include<algorithm>
using namespace std;
bool isPossibleToAllocate(int books[], int n, int limit, int students){
    int allocatedStudents=1,pages=0;
    for(int i=0;i<n;i++){
        if(books[i] > limit)            // if any book size is greater than limit we cannot allocate 
            return false;
                                        // that book to any students hence it is not possible
        if(pages + books[i] <= limit){
            pages += books[i];
        }
        else{
            allocatedStudents++;
            pages = books[i];
        }
    }
    // if allocated students are greater than students, so we cannot allocated all books.
    // if allocated students < students, there might be an answer if we reduce the limit
    return allocatedStudents <= students;
}
int findMinOfMaxAllocatedBooks(int books[], int n, int students){

    if (n<B)     // if no of books is less than students, we cannot allocate books to all students
        return -1;          
    int low = *min_element( books, books+n), high = 0, ans=-1;
    for(int i=0;i<n;i++)
        high += books[i];

    while(low <= high){
        int mid = low + (high-low)/2;
        if(isPossibleToAllocate(books,n,mid, students)){
            ans = mid;
            high = mid-1;          // search on left to get min answer if possible
        }
        else
            low = mid+1;           // search on right to get answer
    }
    return ans;

}
int main() {

    int n, students;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cin>>students;
    cout<<"min of maximum books allocated:"<<findMinOfMaxAllocatedBooks(arr,n,students);

    return 0;
}

/*
4
12 34 67 90
2
min of maximum books allocated:113
*/
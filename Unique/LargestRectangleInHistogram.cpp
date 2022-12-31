// https://leetcode.com/problems/largest-rectangle-in-histogram
#include<iostream>
#include<vector>
#include<stack>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// naive solution
// fix current histogram height and expand, do this for all histograms
// left smaller is index after first element on left smaller than current height
// right smaller is index before first element on right smaller than current height
// area = (right smaller index - left smaller index + 1) * height
// time complexity: O(n^2)
// using stacks
// find index of first smaller element on left for each element using stack
// do same for right, store them in arrays
// time complexity: O(n) + O(n) = O(n)

int largestRectArea_stacks(int n, vector<int> heights){

    stack<int> st;
    vector<int> leftSmall(n), rightSmall(n);

    // find indexes of left smaller elements
    for(int i=0;i<n;i++){

        // pop all elements greater than current element
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        
        // if stack is empty, no smaller element on left
        if(st.empty())
            leftSmall[i] = 0;
        else
            // take index after smaller element, as we can't take smaller height as boundary
            leftSmall[i] = st.top() + 1;

        // push current element index, as it is larger than previous elements in stack
        // we store indexes whose values are in increasing order in stack
        st.push(i);
    }

    // clear stack to reuse it
    while(!st.empty())
        st.pop();
    
    // find indexes of right smaller elements
    for(int i=n-1;i>=0;i--){

        // pop all elements greater than current element
        while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        
        // if stack is empty, no smaller element on right
        if(st.empty())
            rightSmall[i] = n-1;
        else
            // take index before smaller element, as we can't take smaller height as boundary
            rightSmall[i] = st.top() - 1;

        // push current element index, as it is larger than previous elements in stack
        // we store indexes whose values are in increasing order in stack
        st.push(i);
    }

    // find max area
    int maxArea = 0;
    for(int i=0;i<n;i++)
        maxArea = max(maxArea, (rightSmall[i] - leftSmall[i] + 1) * heights[i]);
    
    return maxArea;
}

// single stack
// find index of first smaller element on left for each element using stack
// find both right and left smaller with single stack
// time complexity: O(n) + O(n) = O(n)
int largestRectArea_stack(int n, vector<int> heights){

    stack<int> st;
    int maxArea = 0;

    // traverse 1 extra element to find right smaller for last element
    for(int i=0;i<=n;i++){

        while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){

            // pop all elements greater than current element
            int height = heights[st.top()];
            st.pop();

            int width;
            // if stack is empty, no smaller element on left
            if(st.empty())
                width = i;
            else
                // st.top() is index of first smaller element on left
                width = i - st.top() - 1;


            // find area
            maxArea = max(maxArea, width * height);
        }

        st.push(i);
    }

    return maxArea;
}
int main() {
    fastio();

    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0; i<n; i++)
        cin>>heights[i];
    
    cout<<largestRectArea_stacks(n, heights)<<nl;
    // cout<<largestRectArea_stack(n, heights)<<nl;
    
}

/*
Output:
6
2 1 5 6 2 3
10
*/
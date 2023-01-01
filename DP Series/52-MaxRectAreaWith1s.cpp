// Problem Link: https://bit.ly/33HFz61
#include<iostream>
#include<vector>
#include<stack>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// histogram area
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

int maxAreaWith1s(int n,int m,vector<vector<int>> &mat){

    vector<int> heights(m, 0);
    int maxArea = 0;
    // find histogram area for each row as it's base
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            // if 1, add 1 to height, we're using before row's height
            if(mat[i][j] == 1)
                heights[j]++;
            else
            // if 0, reset height
                heights[j] = 0;
        }
        maxArea = max(maxArea, largestRectArea_stack(m, heights));
    }

    return maxArea;
}
int main() {
    fastio();

    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];

    cout<<maxAreaWith1s(n,m,mat)<<nl;

    return 0;    
}

/*
Output:
5 4
1 0 1 1
1 0 1 1
0 1 0 1
1 1 1 1
0 0 0 1
5
*/
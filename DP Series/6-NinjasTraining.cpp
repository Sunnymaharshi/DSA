// Problem Link: https://bit.ly/3F4yl8z
#include<iostream>
#include<vector>
#define nl "\n"
#define sp " "
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int maxPoints_memo(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){

    if(day==0){

        int maxp = 0;
        for(int task=0;task<3;task++){
            // take valid task with max points
            if(task!=last){
                maxp = max(maxp,points[day][task]);
            }
        }
        return maxp;
    }
    if(dp[day][last]!=-1){      
        // already computed for this day for same last task
        return dp[day][last];
    }
    int maxp=0;
    for(int task=0;task<3;task++){

        if(task!=last){
            // current task points and max points of previous day
            int pts = points[day][task] + maxPoints_memo(day-1,task,points,dp);
            maxp = max(maxp,pts);       // take max points in every possible way
        }
    }
    
    return dp[day][last] = maxp;
}

int maxPoints_tab(vector<vector<int>> &points){

    int n = points.size();

    vector<vector<int>> dp(n,vector<int>(4,0));
    // last is task 0
    dp[0][0] = max(points[0][1],points[0][2]);
    // last is task 1
    dp[0][1] = max(points[0][0],points[0][2]);
    // last is task 2
    dp[0][2] = max(points[0][0],points[0][1]);
    // last is task 3, start day
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){

        for(int last=0;last<4;last++){      // for all possible last tasks

            dp[day][last] = 0;
            for(int task=0;task<3;task++){

                if(task!=last){             // for all valid tasks
                    // do this task and max pts for previous day
                    // with last task as this task
                    int pts = points[day][task] + dp[day-1][task];

                    dp[day][last] = max(dp[day][last],pts);
                }
            }

        }
    }

    // last day n-1 is start day and last task for start day is 3
    return dp[n-1][3];
}
int maxPoints_space_op(vector<vector<int>> &points){

    /* In tabulation, we're only using max points for all possible
    tasks of day-1, we just need to store max points of previous day 
    for all possible last tasks
    */

    int n = points.size();
    vector<int> prev(4,0);
    // last is task 0
    prev[0] = max(points[0][1],points[0][2]);
    // last is task 1
    prev[1] = max(points[0][0],points[0][2]);
    // last is task 2
    prev[2] = max(points[0][0],points[0][1]);
    // last is task 3, start day
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){

        vector<int> cur(4,0);
        for(int last=0;last<4;last++){      // for all possible last tasks

            for(int task=0;task<3;task++){

                if(task!=last){             // for all valid tasks
                    // do this task and max pts for previous day
                    // with last task as this task
                    int pts = points[day][task] + prev[task];

                    cur[last] = max(cur[last],pts);
                }
            }

        }
        // make cur day as prev
        prev = cur;
    }

    return prev[3];             // last task is 3 for start day
}
int32_t main() {
    fastio();

    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }
    // 4th column for max of all tasks for start day
    vector<vector<int>> dp(n,vector<int>(4,-1));        
    // start from last day, 3 specifies we're on start day we can choose all tasks
    // cout<<maxPoints_memo(n-1,3,points,dp);
    // cout<<maxPoints_tab(points);
    cout<<maxPoints_space_op(points);
    return 0;
}
/*
Output:
*/
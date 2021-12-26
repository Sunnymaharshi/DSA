/* https://codeforces.com/problemset/problem/1359/C
for all equal no of h and c cases avg always (h+c)/2
for no of h > no of c, avg always > (h+c)/2
if t<=(h+c)/2, then min avg is (h+c)/2 i.e. h,c -> 2 steps
(h*x + c*(x-1))/(2*x-1) = t for no of h > c, 2*x-1 total cups
from above x = (t-c)/(2*t-h-c)
*/
#include<iostream>
#include<vector>
#define nl "\n"
#define int long long
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int32_t main() {

    fastio();
    int T,h,c,t;
    cin>>T;
    while(T--){
        cin>>h>>c>>t;
        if(h==t){               // as we take atleast 1 hot water cup
            cout<<1<<nl;
            continue;
        }
        if(2*t <= h+c)          // min avg we get is (h+c)/2 with h,c
            cout<<2<<nl;
        else{

            int x = (t-c)/(2*t - h - c);  // avg with x is <= t as we taking floor values
            int y = x+1;        // we might get closer value after t

            long double x_avg = (x*h + (x-1)*c)/(1.0*2*x - 1);
            long double y_avg = (y*h + (y-1)*c)/(1.0*2*y - 1);
            long double x_diff = abs(x_avg - t);
            long double y_diff = abs(y_avg - t);

            if(x_diff <= y_diff)
                cout<<2*x-1<<nl;
            else
                cout<<2*y-1<<nl;

            /*
            You can also find the optimal k with binary search 
            but the formulas are exactly the same and you have to rely on monotonosity as well.
            Also, these formulas can get you the better understanding for the upper bound of the answer.
            Overall complexity: O(1) or O(logh) per testcase.
            */
        }

    }


    return 0;
}

int smallestX()
/*
Output:
3
30 10 20
41 15 30
18 13 18
2
7
1
*/
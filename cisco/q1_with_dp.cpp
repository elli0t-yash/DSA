// The size of the recursive call are neary decrease by half

#include<bits/stdc++.h>
using namespace std;
const int N = 100;

int findMinDel(int start, int end,int dp[N][N], string s) {
    if(start > end) 
        return 0;
    if(start == end)
        return 1;
    if(dp[start][end] != -1) 
        return dp[start][end];
    
    // For single character deletion 
    int res = 1 + findMinDel(start + 1, end, dp, s);

    // For multi characters deletion
    for(int i = start + 1; i <= end; ++i) {
        if(s[start] == s[i]) 
            res = min(res, findMinDel(start + 1, i - 1, dp, s) + findMinDel(i, end, dp, s));
    }
    return res;
}


int main() {
    string s = "baabaa";
    int n = s.length();
    int dp[N][N];
    memset(dp, -1, sizeof dp);
    cout<<findMinDel(0, n - 1, dp, s);
    return 0;
}
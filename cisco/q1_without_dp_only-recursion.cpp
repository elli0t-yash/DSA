#include<bits/stdc++.h>
using namespace std;

int findMinDel(int start, int end, string s) {
    if(start > end) 
        return 0;
    if(start == end)
        return 1;
    
    // For single character deletion 
    int res = 1 + findMinDel(start + 1, end, s);

    // For multi characters deletion
    for(int i = start + 1; i <= end; ++i) {
        if(s[start] == s[i]) 
            res = min(res, findMinDel(start + 1, i - 1, s) + findMinDel(i, end, s));
    }
    return res;
}


int main() {
    string s = "baabaa";
    int n = s.length();
    cout<<findMinDel(0, n - 1,s);
    return 0;
}
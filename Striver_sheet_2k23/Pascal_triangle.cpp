#include<bits/stdc++.h>
using namespace std;

// for print any element in pascal triangle for any given row and column
int nCr(int n, int r) {
    long long res = 1;
    for(int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// printing nth row
// general concept is ans = ans * (row - col)/col
int print_nth_row(int n) {
    long long ans = 1;
    cout<<ans<<" ";
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main() {
    int row_no;
    // int col_no;
    cin>>row_no;
    // cin>>col_no;
    // int res  = nCr(row_no - 1, col_no - 1);
    // cout<<res;
    print_nth_row(row_no);
}
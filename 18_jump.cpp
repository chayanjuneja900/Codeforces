#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    
    int n = 0;
   
    while (n * (n + 1) / 2 < x) {
        n++;
    }
    
    
    if (n * (n + 1) / 2 == x + 1) {
        cout << n + 1 << "\n";
    } else {
        cout << n << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % m]++;
    }
    
    int ans = 0;
    
    
    if (cnt.count(0) && cnt[0] > 0) {
        ans++;
    }
    
   
    for (int r = 1; r <= m / 2; r++) {
        int c1 = cnt.count(r) ? cnt[r] : 0;
        int c2 = cnt.count(m - r) ? cnt[m - r] : 0;
        
        if (c1 == 0 && c2 == 0) continue;
        
        if (r * 2 == m) {
           
            ans++;
        } else {

            ans += 1 + max(0, abs(c1 - c2) - 1);
        }
    }
    
    cout << ans << "\n";
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
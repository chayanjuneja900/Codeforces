#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int n,m;
    cin>>n>>m;

    string ans(m,0); // this means initailizing with ascii 0 ie null

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        for(int j=0;j<m;j++){
            ans[j] ^= s[j];
        }
    }

    for(int i=0;i<n-1;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            ans[j]^=s[j];
        }
    }

    cout<<ans<<endl<<flush;
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
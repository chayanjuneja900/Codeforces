#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    unordered_map<int,int> m;

    long long ans =0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        int msb = log2(x);

        if(m.find(msb)!= m.end()){
            ans += m[msb];

        }
        m[msb]++;
    }
    cout<<ans<<endl;
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
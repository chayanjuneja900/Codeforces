#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
       cin>>a[i];
    }
    
    int i=n-1;
    while(i>0 && a[i]<=a[i-1]){
        i--;

    }
    while(i>0 && a[i]>=a[i-1]){
        i--;
    }
    cout<<i<<endl;
    
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
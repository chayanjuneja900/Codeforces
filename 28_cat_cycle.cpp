#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n,k;
    cin>>n>>k;

    if(n%2==0) {
        cout<< ((k-1)%n)+1<<endl;
        return ;
    }

    int steps_before_col =n/2;
    int skips = (k-1)/steps_before_col;

    long long pos = ((k-1)+skips)%n;
    cout<<pos+1<<endl;
    return;
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
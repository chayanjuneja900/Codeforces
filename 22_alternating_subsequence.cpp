#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];

    }

    
    long long ans =0;

    long long  sign =v[0]*-1;

    for(int i=0;i<n;i++){
        int maxi =INT_MIN;

        while(i<n && sign*1ll*v[i]<0){
            maxi =max(maxi,v[i++]);
        }

        i--;
        ans+= maxi;
        sign*=-1;
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
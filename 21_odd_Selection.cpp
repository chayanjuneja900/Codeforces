#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n,x;
    cin>>n>>x;

    int ct=0;

    for(int i=0;i<n;i++){
        int k;
        cin>>k;

        if(k&1) ct++;
    }

    if((x==n && (ct&1)==0)|| ((x%2)==0)&& ct==n || ct==0 ){
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    
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
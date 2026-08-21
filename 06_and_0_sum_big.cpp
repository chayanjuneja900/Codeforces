#include <bits/stdc++.h>
using namespace std;

const int m =(int)1e9+7;

int binary_exp(int n,int k){
    if(k==0) return 1;

    int rec =binary_exp(n,k/2);

    if(k%2==0) return ((rec%m)*1ll*(rec%m))%m;
    else{
        return (((n*1ll*(rec%m))%m)*1ll*(rec%m))%m;
    }
    return 0;
}


void solve() {
    int n;
    int k;
    cin>>n>>k;

    cout<<binary_exp(n,k)<<endl;
    
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
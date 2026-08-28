#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string a ,b;
    cin>>a>>b;

    a+='0';
    b+='0';

    int ct_0 = 0;
    int ct_1 = 0;

    for(int i=0;i<n;i++){
        if(a[i]=='0') ct_0++;
        else ct_1++;

        bool curr_match =a[i]==b[i];
        bool next_match = a[i+1]==b[i+1];

        if(curr_match!=next_match){
            if(ct_0!=ct_1){
                cout<<"NO"<<endl;
                return;
            }
        }
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
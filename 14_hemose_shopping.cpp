#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> temp =v;

    sort(temp.begin(),temp.end());

    if(n>=2*x){
        cout<<"YES"<<endl;
        return;
    }

    
    else{
        int start = n-x;
        int end = x-1;

        for(int i=start ;i<=end;i++){
            if(temp[i]!=v[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
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
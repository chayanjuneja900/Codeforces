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

    int ct=0;

    for(int i=0;i<n;i++){
        if(a[i]==a[0]) ct++;
    }
    if(ct==n) {
        cout<<"NO"<<endl;
        return;
    }
    int in_col =a[0];
    cout<<"YES"<<endl;

    int col_2;
    vector<int> left;
    for(int i=1;i<n;i++){

        if(a[i]!=in_col){
            cout<<"1"<<" "<<i+1<<endl;
            col_2=i;
        }

        else{
            left.push_back(i);

        }

    }

    for(auto &it: left){
        cout<<it+1<<" "<<col_2+1<<endl;
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
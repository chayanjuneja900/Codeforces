#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<long long,long long > m;

    for(int i=0;i<n;i++){
        cin>>arr[i];
       
    }
    long long ct =0;

    long long sum =accumulate(arr.begin(),arr.end(),0ll);

    if((sum*2)%n!=0){
        cout<<0<<endl;
        return;
    }
    long long target =(sum*2)/n;

    for(int i=0;i<n;i++){
        int key =target-arr[i];

        if(m.find(key)!=m.end()){
            ct+= m[key];
        }
        m[arr[i]]++;

    }
    cout<<ct<<endl;
    
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
#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;
    
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    for(int i= 0;i<n-1;i++){
        if(v[i+1]-v[i]>1) {
            cout<<"NO"<<endl;
            return;
        
        }

    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
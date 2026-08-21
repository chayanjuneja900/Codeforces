#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n,k;
    cin>>n>>k;

    if(n%2==1){
        cout<<1<<" "<<n/2<<" "<<n/2<<endl;
        return;
    }
    else{
        if(n%4==0){
            cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
            return;
        }
        else{
            cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<endl;
            return;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
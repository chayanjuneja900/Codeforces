#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int n,k;
    cin>>n>>k;

   long long  int q = (((n+k-1)/k))*k;

    cout<<((q+n-1)/n)<<endl;



}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();

    }
}
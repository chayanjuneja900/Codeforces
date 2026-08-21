#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<long long> arr;

    for(int i=0;i<n;i++){
        long long  x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),greater<long long>());
    

    long long alice =0;
    long long bob =0;

   for(int i=0;i<n;i++){
    int x =arr[i];

    if(x%2==0 && i%2==0){
        alice+=x;
    }
    if(x%2==1 && i%2==1){
        bob+=x;
    }


   }

    if(alice > bob){
        cout<<"Alice"<<endl;

    }
    else{
        if(bob>alice){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Tie"<<endl;
        }
    }
   
    
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t ;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
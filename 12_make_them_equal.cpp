#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char c;
    cin>>n>>c;

    string s;
    cin>>s;
    bool is_true =true;

    for(int i=0;i<n;i++){
        if(s[i]!=c){
            is_true=false;
            break;
    }
    }
    if(is_true){
        cout<<0<<endl;
    }
    else{
        bool found =false;
        int k=n/2;
        for(int i=n/2;i<n;i++){
            if(s[i]==c){
                found=true;
                k=i+1;
                break;
            }
        }
        if(found){
       
            cout<<1<<endl;
            cout<<k<<endl;
        }
        else{
            cout<<2<<endl;
            cout<<n<<" "<<n-1<<endl;
            
        }
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
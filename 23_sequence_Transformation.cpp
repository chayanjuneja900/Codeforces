#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> freq(n+1,0);

    for(int i=0;i<n;i++){
        while(i<n-1 && v[i]==v[i+1]){
            i++;
        }
        freq[v[i]]++;
    }

    int ind=-1;

    int mini = INT_MAX;

    for(int i=1;i<=n;i++){
        if(freq[i]!=0){

            mini =min(mini,freq[i]+1-(v[0]==i)-(v[n-1]==i));
            
        }

    }
    cout<<mini<<endl;

   
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
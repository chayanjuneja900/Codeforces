#include <bits/stdc++.h>
using namespace std;

bool helpful(long long h,vector<int> &arr,long long k){
    long long ct=0;

    long long start =arr[0];
    long long end =start+k;

    for(int i=1;i<arr.size();i++){
        start =arr[i];
        if(start>=end){
            ct+=k;
           

        }
        else{
            long long  gap =end -start;
            ct += k-gap;
            
        }
        end =start+k;
    }
    ct+=k;

    return ct>=h;
}

void solve() {
    long long n,h;
    cin>>n>>h;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long hi =h;
    long long lo =1;

    long long mid ;

    while(hi-lo>1){
        mid = lo + (hi-lo)/2;

        if(helpful(h,arr,mid)){
            hi =mid;
        }
        else{
            lo =mid+1;
        }


    }
    if(helpful(h,arr,lo)){
        cout<< lo<<endl;
        return;
    }
    cout<< hi<<endl;
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
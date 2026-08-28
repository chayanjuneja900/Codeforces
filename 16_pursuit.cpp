#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin>>n;

    vector<long long> a(n);
    for (int  i = 0; i < n; i++)
    {
       cin>>a[i];
    }

    vector<long long> b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    sort(a.begin(),a.end(),greater<long long>());
    sort(b.begin(),b.end(),greater<long long>());
    

    vector<long long>pref_A(n+1,0);
    vector<long long>pref_B(n+1,0);

    for(int i=0;i<n;i++){
        pref_A[i+1]=pref_A[i]+a[i];
        pref_B[i+1]=pref_B[i]+b[i];
    }

    long long  lo=0;
    long long  hi =n;
    long long  mid;
    long long ans =hi;

    while(lo<=hi){

        mid = lo + (hi-lo)/2;

        long long total = n+mid;
        long long k = total - (total/4);

        long long take_100 = min(mid,k);
        long long left_a = k-take_100;

        long long score_A = (100ll*take_100) + pref_A[left_a];

        long long take_b=min(n,k);
        long long score_B =pref_B[take_b];

        if(score_A>=score_B){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
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
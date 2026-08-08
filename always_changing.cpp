#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ct_0=0;
        int ct_1=0;

        for(auto &it :s){
            if(it=='0') ct_0++;
            if(it=='1') ct_1++;
        }

        if(ct_0>ct_1){
            swap(ct_0,ct_1);
        }

        int ans =0;

        if(ct_0 ==ct_1-1 || ct_0==ct_1) {
            cout<<ans<<endl;
            continue;
        }

        int k =ct_1 -ct_0-1;
        ans+= k;
        ct_1 -=k;
        ct_0 -= k-1;
        ans+= k-1;

        if(ct_0==ct_1){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
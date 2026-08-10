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
        for(int i=0;i<n;i++){
            if(s[i]=='0') ct_0++;
        }

       if(ct_0%2==1 && ct_0>1){
        cout<<"ALICE"<<endl;
        continue;
       }
       if(ct_0%2==0){
        cout<<"BOB"<<endl;
        continue;

       }
       if(ct_0==1) {
        cout<<"BOB"<<endl;
        continue;
       }
    }
}
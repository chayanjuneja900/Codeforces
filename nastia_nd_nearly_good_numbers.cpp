#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;

        if(b==1) {
            cout<<"NO"<<endl;
            continue;
        }

        else{
            cout<<"YES"<<endl;
            cout<<a<<" "<<a*1ll*b<<" "<<a*1ll*(b+1)<<endl;
        }
    }
}
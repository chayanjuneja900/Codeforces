#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> v(n+1);

        for(int i=1;i<=n;i++){
            cin>>v[i];

        }

        long long ct =0;

        for(int i=1;i<=n;i++){
            int st = v[i]- (i%v[i]);

            for(int j=st;j<=n;j+=v[i]){
                if(i<j && v[i]*1ll*v[j]==i+j) ct++;
            }
        }
        cout<<ct<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        long long ct=0;

        unordered_map<long long,long long > m;

       
        for(int i=0;i<n;i++){
            int x;
            cin>>x;

            int var = x-i;
            if(m.find(var)!= m.end()){
                ct += m[var];
            }
            m[var]++;

            
        }
        cout<<ct<<endl;

    }
}
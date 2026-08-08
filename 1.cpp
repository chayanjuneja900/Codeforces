#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    int n=s.size();

     long long sum =0;
            int ct =0; 
             

            for(int i=0;i<n;i++){
                while(i<n-1 && s[i]==s[i+1]){
                    i++;
                    
                    
                }
                ct++;
            }
            cout<<ct<<endl;
}
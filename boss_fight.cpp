#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
    
        unordered_map<int,int> m;
        vector<int> v(n);

        for(int i=0;i<n;i++){
            int x;
        
            cin>>x;
            v[i]=x;
            m[x]++;
            
        }
        int mx =INT_MIN;
        pair<int,int> k;

        for(auto &it : m){

            if(it.second>mx){
                mx =it.second;
                k ={it.first,it.second};
            }
        }

        int freq = k.second;
        long long sum ;

        int s =n-freq;

        if(freq -1<=s){
            sum =accumulate(v.begin(),v.end(),0*1ll);

        }

        else{
            sum=0;
            for(auto &it: v){
                if(it ==k.first) continue;

                sum +=it;
            }
            sum += k.first*(s+2);
        }

       

        
cout<<sum<<endl;
        
        
    }
}
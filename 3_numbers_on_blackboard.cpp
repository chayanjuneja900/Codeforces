#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        vector<int>v ={a,b,c};

        sort(v.begin(),v.end());

        int maxi = INT_MAX;

        while(true){
            

            int top =v[2];
            int bottom =v[0];

            int temp =maxi;

            maxi =min(top-bottom,maxi);

            if(maxi ==temp) break;

            v[2]=v[1]+v[0];


        }
        cout<<maxi<<endl;
    }
}
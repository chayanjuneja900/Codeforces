#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;

        if(b>=0) {
            cout<<n*1ll*(a+b)<<endl;
            continue;
        }
        else{
            long long sum =0;
            int ct =0; 
             

            for(int i=0;i<n;i++){
                while(i<n-1 && s[i]==s[i+1]){
                    i++;   
                }
                ct++;
            }

            int k =ct/2 +1;

            sum +=a*1ll*n + b*1ll*k;
            cout<<sum<<endl;

        }
    }
}
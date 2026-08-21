#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;

    int s1=0;
    int s2=0;

    int k1=5;
    int k2=5;

    int ans =INT_MAX;

    //team 1 turn

    for(int i=0;i<10;i++){
        if(i%2==0){

            if(s[i]=='1' || s[i]=='?'){
                s1++;
                
            }
            k1--;

            if(s1>s2+k2){
                ans = min(ans,10-k1-k2);
                break;
            }
            
        }
        else{
            if(s[i]=='1'){
                s2++;
            }
            k2--;
             if(s1>s2+k2){
                ans = min(ans,10-k1-k2);
                break;
            }
        }
    }

    // team 2 

    s1 =0;
    s2=0;
    k1=5;
    k2=5;

    

    for(int i=0;i<10;i++){
        if(i%2==0){

            if(s[i]=='1'){
                s1++;
                
            }
            k1--;

            if(s2>s1+k1){
               ans = min(ans,10-k1-k2);
                break;
            }
            
        }
        else{
            if(s[i]=='1'||s[i]=='?'){
                s2++;
            }
            k2--;
             if(s2>s1+k1){
                ans = min(ans,10-k1-k2);
                break;
            }
        }
    }
    if(ans!= INT_MAX) cout<<ans<<endl;
    else{
        cout<<10<<endl;
    }
    
return;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
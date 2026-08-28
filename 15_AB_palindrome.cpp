#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b;
    cin>>a>>b;

    string s;
    cin>>s;
     int n=s.size();

    if((a&1) && (b&1) ){
        cout<<-1<<endl;
        return;

    }
    
    int ct_0=0;
    int ct_1=0;

    vector<int> ind;

    for(int i=0;i<n/2;i++){
        if(s[i]==s[n-i-1]){
            if(s[i]=='0') ct_0+=2;
            if(s[i]=='1') ct_1+=2;
            if(s[i]=='?') ind.push_back(i);
        }
        else{
            if(s[i]=='?' || s[n-i-1] =='?'){
                if(s[i]=='?'){
                    if(s[n-i-1]=='0'){
                        ct_0+=2;
                        s[i]='0';
                    }
                    if(s[n-i-1]=='1'){
                        ct_1+=2;
                        s[i]='1';
                    }
                }
                else{
                    if(s[i]=='0'){
                        ct_0+=2;
                        s[n-1-i]='0';
                    }
                     if(s[i]=='1'){
                        ct_1+=2;
                        s[n-1-i]='1';
                    }
                }
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }

    if(n%2==1){
        if(a%2==1 && s[n/2]=='1'){
            cout<<-1<<endl;
            return;
        }
        if(b%2==1 && s[n/2]=='0'){
            cout<<-1<<endl;
            return;

        }
        if(a%2==1){
            ct_0+=1;
            s[n/2]='0';
        }
         
         if(b%2==1){
            ct_1+=1;
            s[n/2]='1';
        }   
    }
    for(auto &it : ind){
        if(ct_0<a){
            ct_0+=2;
            s[it]='0';
            s[n-1-it]='0';
            continue;
        }
         if(ct_1<b){
            ct_1+=2;
            s[it]='1';
            s[n-1-it]='1';
            continue;
        }

        cout<<-1<<endl;
        return;

    }
    if(ct_0==a && ct_1==b){
        cout<<s<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
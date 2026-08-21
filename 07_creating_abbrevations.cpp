#include<bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;

    unordered_set<char> s;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;

        char a = (char)(x[0]-'a'+'A');

       s.insert(a);
    }
    bool is_true=true;

    while(m--){
        string x;
        cin>>x;
       
       for(auto &a :x){ 
       
        if(s.find(a)==s.end()){
           is_true=false;
        }
    }

    }
    if(is_true) cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
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
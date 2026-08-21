#include<bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9+7;

void solve(){

    int n,m;
    cin>>n>>m;

    vector<int> bea(n);

    for (int i = 0; i < n; i++)
    {
        cin>>bea[i];
    }

    vector<int> ver(m);
    
    for (int i = 0; i < m; i++)
    {
        cin>>ver[i];
    }

    long long attack_1=0;
    long long attack_2=0;

    for(int i=0;i<m;i++){
        if(i+1<m){

            attack_1 += ver[i]-ver[i+1]+1;
            continue;
        }
        attack_1 += ver[i];
    }

     for(int i=0;i<n;i++){
        if(i+1<n){

            attack_2 += bea[i]-bea[i+1]+1;
            continue;
        }
        attack_2 += bea[i];
    }

    if(attack_1<=attack_2){
        cout<<1<<endl;
    }
    else{
        cout<<2<<endl;
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
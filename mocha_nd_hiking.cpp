#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    
    vector<int> v(n+1);

    for(int i=1;i<n+1;i++){
        cin>>v[i];
    }

    //case 1
    if(v[n]==0){
        for(int i=1;i<=n+1;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return ;
    }

    if(v[1]==1){
        cout<<n+1<<" ";
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return ;
    }

    bool found =false;
    int k =-1;

    for(int i=1;i<n;i++){
        
        if(v[i]==0 && v[i+1]==1){
            k=i;
            found =true;
            break;

        }
}

if(found){
        for(int j=1;j<=k;j++){
            cout<<j<<" ";
        }
        cout<<n+1<<" ";
        

        for(int j=k+1;j<n+1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
        return ;
    }
    cout<<"-1"<<endl;
    return;
}




int main(){
    int t;
    cin>>t;
    while(t--){
      solve();
    }
}
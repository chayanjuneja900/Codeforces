#include<bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9+7;

void solve(){
    int n;
    cin>>n;

    vector<int> parent(n+1);

    for(int i=2;i<=n;i++){
       cin >> parent[i];
    }
    int m;
    cin>>m;
    
    vector<int> is_dam(n+1,0);
    vector<int> has_dam(n+1,0);

    for (int i = 0; i < m; i++)
    {
       
        int x;
        cin>>x;

        is_dam[x]=1;
        has_dam[x]=1;
    }

    vector<int> dams;

    for(int i=n;i>=2;i--){
        

        if(has_dam[i]){
            int p =parent[i];
            if(is_dam[p]){
            dams.push_back(i);
            }
        
        else{
            if(has_dam[p]){
                dams.push_back(i);
            }
        }
        has_dam[p]=1;
    }
}
    
    cout<<dams.size()<<" ";

    for(auto &it : dams){
        cout<<it<<" ";
    }
    cout<<endl;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
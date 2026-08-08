#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> stab(n);

        for (int i = 0; i < n; i++)
        {
            cin>>stab[i];
        }

        vector<vector<int>> mat(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }

        int mx =m;

        priority_queue<int> q;

        for(int i=n-1;i>=0;i--){

            for(int j=0;j<m;j++){
                q.push(mat[i][j]);
            }

            long long sum=0;

            vector<int> used;

            for(int k=1;k<mx;k++){
                int curr=q.top();
                q.pop();

                sum+= curr;
                used.push_back(curr);


                if(sum>=stab[i]){
                    mx=k;
                    break;
                }
            }
            for(auto &it: used){
                q.push(it);
            }

        }

        cout<<mx<<endl;

        
        
    }
}
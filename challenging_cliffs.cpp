#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> heights(n);

        for(int i=0;i<n;i++){
            cin>>heights[i];

        }

        sort(heights.begin(),heights.end());

        if(n==2){
            for(auto &it :heights){
                cout<<it<<" ";
            }
            cout<<endl;
            continue;
        }

        int start=-1;

        int mn =INT_MAX;

        for(int i=0;i<n-1;i++){
            if(heights[i+1]-heights[i]<mn){
                start =i;
                mn =heights[i+1]-heights[i];
            }
        }



        cout<<heights[start]<<" ";

        for(int i= start+2;i<n;i++){
            cout<<heights[i]<<" ";

        }
        if(start!=0){
            for(int i=0;i<start;i++){
                cout<<heights[i]<<" ";
            }
        }
        cout<<heights[start+1]<<endl;
        
    }
}
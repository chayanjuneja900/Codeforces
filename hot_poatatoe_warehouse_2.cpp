#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<int> v;
        int first =-1;

        for(int i=0;i<2*n;i++){
            if(first ==-1 && s[i]=='1'){
                first =i;
            }
            if(s[i]=='1')  v.push_back(i);
        }

        int red =0;
        int blue =0;
        
       
        if(v.empty()){
            cout << "0 0\n";
            continue;
        }

        if(v.size()==1){
            if(v[0]%2==0) red++;  
            else blue++;          
            cout<<red<<" "<<blue<<endl;
            continue;
        }
        
        v.push_back(first);

        for(int i=0;i<v.size()-1;i++){
            if((v[i+1]-v[i]-1)==0){
                
                if(v[i]%2==0) blue++; 
                else red++;           
            }
            else{
                if((v[i+1]-v[i]-1)>0){
                   
                    if(v[i]%2==0) red++;  
                    else blue++;          
                }
                else{
                    
                    if((v[i+1]-v[i]-1+(2*n))>0) {
                        if(v[i]%2==0) red++;  
                        else blue++;          
                    }
                    else{
                         if(v[i]%2==0) blue++; 
                         else red++;           
                    }
                }
            }
        }

        cout<<red<<" "<<blue<<endl;
    }
}
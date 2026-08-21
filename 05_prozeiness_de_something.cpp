#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    unordered_set <string> st;

    //1 length

    for(int i=0;i<n;i++){
        st.insert(s.substr(i,1));

        if(i+1<n) st.insert(s.substr(i,2));
        if(i+2<n) st.insert(s.substr(i,3));
    }

    string mex= "";

    for(int i=0;i<26;i++){
        

                mex += (char)('a'+i);
           

            if(st.find(mex)!=st.end()) {
                mex="";
                continue;
            }

            cout<<mex<<endl;
            return;

        
    }
    mex="";


    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            

                mex += (char)('a'+i);
                mex += (char)('a'+j);
            

          
            if(st.find(mex)!=st.end()) {
                mex="";
                continue;
            }

            cout<<mex<<endl;
            return;

        }
    }

    mex ="";
    


    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            for(int z=0;z<26;z++){

                mex += (char)('a'+i);
                mex += (char)('a'+j);
                mex += (char)('a'+z);

                if(st.find(mex)!=st.end()) {
                mex="";
                continue;
            }
            cout<<mex<<endl;
            return;
            
            }

            

        }
    }

}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
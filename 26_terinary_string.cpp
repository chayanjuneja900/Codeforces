#include <bits/stdc++.h>
using namespace std;

bool check(string s,int mid){

    int ct_1=0;
    int ct_2=0,ct_3=0;
  

    int i=0;
    for(i=0;i<mid;i++){
        if(s[i]=='1') ct_1++;
        else{
            if(s[i]=='2') ct_2++;
            else
              ct_3++;
        }

         if(ct_1>0 && ct_2>0 && ct_3>0) return true;
    }
    while(i<s.size()){
       

        if(s[i-mid]=='1') ct_1--;
        else{
            if(s[i-mid]=='2') ct_2--;
            else ct_3--;
        }


        if(s[i]=='1') ct_1++;
        else{
            if(s[i]=='2') ct_2++;
            else
              ct_3++;
        }

        if(ct_1>0 && ct_2>0 && ct_3>0) return true;
         i++;

    }
    return false;
}

void solve() {
    string s;
    cin>>s;


    int ct_1=0;
    int ct_2=0,ct_3=0;
  
    for(int i=0;i<s.size();i++){
       if(s[i]=='1') ct_1++;
        else{
            if(s[i]=='2') ct_2++;
            else
              ct_3++;
        }
    }

    if(ct_1==0 || ct_2==0 || ct_3==0){
        cout<<0<<endl; 
        return ;
    }
    int n=s.size();


    int lo =3; 
    int hi =n;
     int mid;

     while(hi-lo>1){
        mid = lo + (hi-lo)/2;

        if(check(s,mid)){
            hi=mid;
        }
        else lo=mid+1;

     }

     if(check(s,lo)) cout << lo<<endl;
    else cout<<hi<<endl;
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
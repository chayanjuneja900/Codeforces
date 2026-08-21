#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a,s;
    cin>>a>>s;

    int i=a.size()-1,j=s.size()-1;

    string b="";

    while (j>=0){

        int dig_a = (i>=0)? a[i]-'0' : 0;
        int dig_s= s[j]-'0';

        if(dig_s < dig_a){
            j--;
            if(j<0){
                cout<<-1<<endl;
                return;
            }
            dig_s = ((s[j]-'0')*10)+ dig_s;
        }

        int key = dig_s-dig_a;

        if(key<0 || key>9){
            cout<<-1<<endl;
            return ;
        }

        b = (char)(key+'0') + b;
        i--;
        j--;
    }

   if(i>=0){
    cout<<-1<<endl;
    return;
   }

   while((b.size()> 1) && b[0]=='0'){
    b.erase(b.begin());
   }

    cout<<b<<endl;

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
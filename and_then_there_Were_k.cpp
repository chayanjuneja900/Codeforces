#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int ans =n;

        int k =log2(n);
        cout<<(1<<k)-1<<endl;
    }
}

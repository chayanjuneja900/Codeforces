#include<bits/stdc++.h>
using namespace std;

long long sum (long long n){
    long long  k=0;
    while(n>0){
        k+= n%10;
        n/=10;

    }
    return k;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n ;
        cin>>n;

        while(__gcd(n,sum(n))==1){
            n++;
        }
        cout<<n<<endl;
    }
}
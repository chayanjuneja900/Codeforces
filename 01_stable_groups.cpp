#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k,x;
    cin>>n>>k>>x;

    vector<long long> students(n);

    for(int i=0;i<n;i++){
        cin>>students[i];
    }

    sort(students.begin(),students.end());

    vector<long long> gaps;

    for(int i=0;i<n-1;i++){
        if(students[i+1]-students[i]>x){

            long long z= (students[i+1]-students[i]-1)/x;

            gaps.push_back(z);
        }
    }
    sort(gaps.begin(),gaps.end());

    int sz =gaps.size()+1;
    int i=0;

    while(i<gaps.size() && k>0){
        if(k>=gaps[i]){
            k-= gaps[i];
            i++;
            sz--;
            
        }
        else{
            break;
        }

       
    }
     cout<<sz<<endl;

}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int,int> m;

        for(auto &it : reservedSeats){
            int row =it[0];
            int seat =it[1];

            m[row]|= (1<<seat);
        }

        int ans =0;

        ans += (n-m.size())*2;
        
        int left = (1<<2)|(1<<3)|(1<<4)| (1<<5);
        int right = (1<<6)|(1<<7)|(1<<8)| (1<<9);
        int mid = (1<<4)|(1<<5)|(1<<6)| (1<<7);

        for(auto &it :m){
            auto mask = it.second;

            if((mask & left)==0 && (mask & right)==0){
                ans+=2;
            }
            else{
                if((mask & left)==0 || (mask & mid)==0 || (mask & right)==0){
                    ans+= 1;

                }
            }
        }
        return ans;
    }
};

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
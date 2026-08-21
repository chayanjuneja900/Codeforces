#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    
    if (n == 2) {
        cout << -1 << "\n";
        return;
    }

    int current_odd = 1;
    int current_even = 2;
    int max_val = n * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (current_odd <= max_val) {
                cout << current_odd << " ";
                current_odd += 2;
            } else {
                cout << current_even << " ";
                current_even += 2;
            }
        }
        cout << "\n";
    }
}

int main() {
   

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
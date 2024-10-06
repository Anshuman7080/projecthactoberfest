#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;

    // Check if n is a power of 2
    if (x == 0 && n % 2 == 1) {
        cout << -1 << "\n";
        return;
    }

    if (n <= x || (n & (n - 1)) == 0) {
        // If n is a power of 2 or x is larger than or equal to n
        cout << 1 << "\n";
        return;
    }

    vector<long long> powers;
    for (int i = 0; (1LL << i) <= n; ++i) {
        if (n & (1LL << i)) { // Check if the i-th bit is set
            if (i == 0) {
                powers.push_back(1);
            } else if (i % 2 == 0) {
                powers.push_back(1LL << (i - 1));
                powers.push_back(1LL << (i - 1)); // Add twice for even positions
            } else {
                powers.push_back(1LL << i);
            }
        }
    }

    long long sum = 0;
    int k = 0;
    for (const auto& p : powers) {
        sum += p;
        k++;
        if (sum > x) {
            k--; // Decrease count if we exceed x
            break;
        }
    }

    cout << (k > 0 ? powers.size() - k + 1 : powers.size() - k) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    
    return 0;
}

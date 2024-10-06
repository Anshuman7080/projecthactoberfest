#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> dict(B.begin(), B.end());  // Convert vector to set for O(1) lookups
        int len = A.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;  // Base case: empty string can always be segmented

        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < i; j++) {
                // If substring A[j:i] is in the dictionary and A[0:j] can be segmented
                if (dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;  // No need to check further
                }
            }
        }
        
        return dp[len] ? 1 : 0;  // Return 1 if the entire string can be segmented, otherwise 0
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dict(n);
        for (int i = 0; i < n; i++) {
            cin >> dict[i];
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
    return 0;
}

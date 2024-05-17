//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int editDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        // Create a dp table of size (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Initialize the dp table
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[i][j] = j;  // s is empty, insert all characters of t
                } else if (j == 0) {
                    dp[i][j] = i;  // t is empty, remove all characters of s
                } else if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // Characters match, no operation needed
                } else {
                    dp[i][j] = 1 + min({ dp[i - 1][j],    // Delete
                                         dp[i][j - 1],    // Insert
                                         dp[i - 1][j - 1] // Replace
                                       });
                }
            }
        }
        
        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
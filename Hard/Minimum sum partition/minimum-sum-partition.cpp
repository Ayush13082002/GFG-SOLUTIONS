//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int minDifference(int arr[], int n) {
        // Calculate the total sum of the elements in the array
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += arr[i];
        }

        // Create a 2D boolean array to store the possible sums
        bool dp[n + 1][totalSum + 1];

        // Initialize the first column with true (sum 0 can always be achieved)
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        // Initialize the first row (sum 0 can always be achieved with no elements)
        for (int j = 1; j <= totalSum; ++j) {
            dp[0][j] = false;
        }

        // Fill the dp table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= totalSum; ++j) {
                // Check if the current element can contribute to the sum
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Find the minimum difference
        int minDiff = totalSum;
        for (int j = totalSum / 2; j >= 0; --j) {
            if (dp[n][j]) {
                minDiff = totalSum - 2 * j;
                break;
            }
        }

        return minDiff;
    }
};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    int findPair(int n, int x, std::vector<int> &arr) {
        // Sort the array
        std::sort(arr.begin(), arr.end());
        
        int i = 0;
        int j = 1;
        
        // Use two-pointer technique to find the pair with absolute difference x
        while (i < n && j < n) {
            // Calculate the difference between arr[j] and arr[i]
            int diff = arr[j] - arr[i];
            
            if (diff == x) {
                return 1; // Pair found
            } else if (diff < x) {
                j++; // Increase the difference
            } else {
                i++; // Decrease the difference
            }
            
            // Ensure the two pointers are not pointing to the same element
            if (i == j) {
                j++;
            }
        }
        
        return -1; // No such pair exists
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int left = 0, right = a.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (a[mid] > a[mid + 1]) {
                // Peak must be in the left part including mid
                right = mid;
            } else {
                // Peak must be in the right part excluding mid
                left = mid + 1;
            }
        }
        
        // When left == right, we have found the peak element
        return a[left];
    }
};




//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends
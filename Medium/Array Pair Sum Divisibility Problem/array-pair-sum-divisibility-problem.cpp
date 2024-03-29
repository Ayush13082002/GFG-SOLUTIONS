//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
       int n = nums.size();
        if(n % 2) return false;
        vector<int> mp(k + 1, 0); 
        for(auto x : nums){
            x %= k;
            mp[x]++;
            mp[k-x]--;
        } 
        for(int i = 1; i < k; i++) if(mp[i]>0) return false;
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
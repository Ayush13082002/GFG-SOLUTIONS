//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string smallestWindow(string s, string p) {
        vector<int> p_count(26, 0);
        vector<int> s_count(26, 0);

        // Populate the count of characters in string p
        for (char c : p) {
            p_count[c - 'a']++;
        }

        int required_chars = 0;
        for (int count : p_count) {
            if (count > 0) {
                required_chars++;
            }
        }

        int formed_chars = 0;
        int start = 0;
        int min_len = numeric_limits<int>::max();
        int min_start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char curr_char = s[end];
            s_count[curr_char - 'a']++;

            // If the current character forms a required character
            if (p_count[curr_char - 'a'] > 0 && s_count[curr_char - 'a'] == p_count[curr_char - 'a']) {
                formed_chars++;
            }

            // If all required characters are found in the current window
            while (formed_chars == required_chars) {
                // Update the minimum window length and starting index
                if (end - start + 1 < min_len) {
                    min_len = end - start + 1;
                    min_start = start;
                }

                // Shrink the window from the left
                char left_char = s[start];
                s_count[left_char - 'a']--;
                if (p_count[left_char - 'a'] > 0 && s_count[left_char - 'a'] < p_count[left_char - 'a']) {
                    formed_chars--;
                }
                start++;
            }
        }

        // If no window found
        if (min_len == numeric_limits<int>::max()) {
            return "-1";
        }

        return s.substr(min_start, min_len);
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
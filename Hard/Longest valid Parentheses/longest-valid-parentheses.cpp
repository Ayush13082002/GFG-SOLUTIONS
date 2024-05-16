//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxLength(string S) {
        stack<int> st;
        st.push(-1); // Initialize the stack with a dummy index

        int maxLen = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                st.push(i); // Push the index of opening parenthesis
            } else { // Closing parenthesis encountered
                st.pop(); // Pop the corresponding opening parenthesis index
                if (!st.empty()) {
                    maxLen = max(maxLen, i - st.top()); // Calculate the length of valid substring
                } else {
                    st.push(i); // If stack is empty, push the current index as a new dummy
                }
            }
        }

        return maxLen;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
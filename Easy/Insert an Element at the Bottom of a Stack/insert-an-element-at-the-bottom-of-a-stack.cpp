//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <stack>

class Solution {
public:
    std::stack<int> insertAtBottom(std::stack<int> st, int x) {
        // Base case: if the stack is empty, push x onto it
        if (st.empty()) {
            st.push(x);
        } else {
            // Remove all items from stack and store them in a temporary stack
            std::stack<int> tempStack;
            while (!st.empty()) {
                tempStack.push(st.top());
                st.pop();
            }

            // Insert x at the bottom of the stack
            st.push(x);

            // Push back all the elements from the temporary stack to the original stack
            while (!tempStack.empty()) {
                st.push(tempStack.top());
                tempStack.pop();
            }
        }
        return st;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
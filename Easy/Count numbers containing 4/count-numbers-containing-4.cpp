//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) 
    {
        int c=0;
        for(int i=n;i>3;i--)
        {
            
            int m=log(i);
            string s=to_string(i);
            for(int j=0;j<m;j++)
            {
                if(s[j]=='4')
                {
                    c++;
                    break;
                }
                
            }
        }
        return c;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends
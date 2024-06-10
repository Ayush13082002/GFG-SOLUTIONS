//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {

  public:

 

    void matchPairs(int n, char nuts[], char bolts[]) {

        string str="!#$%&*?@^~.";

        int p=0;

        for(int i=0;i<10;i++)

        {

            for(int j=0;j<n;j++)

            {

                if(nuts[j]==str[i])

                {

                    swap(nuts[j],nuts[p]);

                    bolts[p]=nuts[p];

                    

                    p++;

                    if(p>n-1)

                    {

                        break;

                    }

                }

            }

        }

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
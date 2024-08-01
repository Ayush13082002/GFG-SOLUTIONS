//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size(),m=matrix[0].size(),s=n*m;
        //a -> row start, b -> col start, c -> row end, d -> col end
        int a=0,b=0,c=n-1,d=m-1;
        vector<int> ans;
        while(ans.size()<s){
            for(int i=b;i<=d && ans.size()<s;i++)ans.push_back(matrix[a][i]);
            a++;
            for(int i=a;i<=c && ans.size()<s;i++)ans.push_back(matrix[i][d]);
            d--;
            for(int i=d;i>=b && ans.size()<s;i--)ans.push_back(matrix[c][i]);
            c--;
            for(int i=c;i>=a && ans.size()<s;i--)ans.push_back(matrix[i][b]);
            b++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
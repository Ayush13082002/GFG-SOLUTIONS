//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> s;
        long long maxArea = 0;
        int i = 0;

        while (i < n)
        {
            if (s.empty() || arr[i] >= arr[s.top()])
            {
                s.push(i);
                i++;
            }
            else
            {
                int topIndex = s.top();
                s.pop();
                long long area = arr[topIndex] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, area);
            }
        }

        while (!s.empty())
        {
            int topIndex = s.top();
            s.pop();
            long long area = arr[topIndex] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
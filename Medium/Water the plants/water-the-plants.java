//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;

class GFG {
	public static void main (String[] args)throws IOException {
		
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out=new PrintWriter(System.out);
		int t = Integer.parseInt(in.readLine().trim());
        while(t-- > 0)
        {
            int n = Integer.parseInt(in.readLine().trim());
            String s[]=in.readLine().trim().split(" ");
            
            int gallery[] = new int[n];
            for(int i=0; i<n; i++)
                gallery[i] = Integer.parseInt(s[i]);
            Solution T = new Solution();
            out.println(T.min_sprinklers(gallery,n));
        }
		out.close();
		
	}
}





// } Driver Code Ends


//User function Template for Java
class Solution
{
    int min_sprinklers(int gallery[], int n)
    {
        int[][] sprinklers = new int[n][2];

        for (int i = 0; i < n; i++) {
            if (gallery[i] == -1)
                continue;

            int left = Math.max(0, i - gallery[i]);
            int right = Math.min(n - 1, i + gallery[i]);

            sprinklers[i][0] = left;
            sprinklers[i][1] = right;
        }

        Arrays.sort(sprinklers, Comparator.comparingInt(a -> a[0]));

        int count = 0;
        int i = 0;
        int target = 0;

        while (target < n) {
            int maxEnd = -1;
            while (i < sprinklers.length) {
                if (sprinklers[i][0] > target)
                    break;
                maxEnd = Math.max(maxEnd, sprinklers[i][1]);
                i++;
            }

            if (maxEnd < target) {
                return -1;
            }

            count++;
            target = maxEnd + 1;
        }

        return count;
    }
}

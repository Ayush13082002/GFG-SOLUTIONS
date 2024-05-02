//{ Driver Code Starts
//Initial Template for Java


import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function Template for Java


class Solution
{   static  int MOD = 1000000007;
    public static int ways(int x, int y)
    {
        // complete the function
        int memo[][] = new int[x+1][y+1];
        for(int row[] : memo)
        Arrays.fill(row,-1);
        
        return dfs(x,y,memo);
    }
    static int dfs(int x, int y, int memo[][]){
        if(x==0 && y==0) return 1;
        
        if(memo[x][y]!=-1) return memo[x][y];
        
        int cnt=0;
        if(x>0)
        cnt = (cnt + dfs(x-1,y,memo))%MOD;
        
        if(y>0)
        cnt = (cnt + dfs(x,y-1,memo))%MOD;
        
        return memo[x][y] = cnt;
    }
}

//{ Driver Code Starts.

// Driver class
class Array {
    
    // Driver code
	public static void main (String[] args) throws IOException{
		// Taking input using buffered reader
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		// looping through all testcases
		while(testcases-- > 0){
		    String line = br.readLine();
		    String[] elements = line.trim().split("\\s+");
		    int x=Integer.parseInt(elements[0]);
		    int y=Integer.parseInt(elements[1]);
		    Solution ob = new Solution();
		    System.out.println(ob.ways(x,y));
		}
	}
}
// } Driver Code Ends
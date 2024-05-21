#User function Template for python3

class Solution:
    def printKClosest(self, arr, n, k, x):
        # code here
        b = sorted( [[i,abs(i-x)] for i in arr if i!=x] ,key=lambda q:(q[1],-q[0]) )[:k]
        return [i[0] for i in b]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k, x = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.printKClosest(arr, n, k, x)
        for xx in ans:
            print(xx, end=" ")
        print()
        tc -= 1

# } Driver Code Ends
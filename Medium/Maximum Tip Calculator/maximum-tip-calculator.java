//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            int x;
            x = Integer.parseInt(br.readLine());

            int y;
            y = Integer.parseInt(br.readLine());

            int[] arr = IntArray.input(br, n);

            int[] brr = IntArray.input(br, n);

            Solution obj = new Solution();
            long res = obj.maxTip(n, x, y, arr, brr);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    // Inner class to represent each order with tips given by person A and person B
    static class Order {
        int tipA; // Tip given by person A
        int tipB; // Tip given by person B

        // Constructor to initialize the tips for an order
        Order(int tipA, int tipB) {
            this.tipA = tipA;
            this.tipB = tipB;
        }
    }

    // Method to calculate the maximum possible tips
    public static long maxTip(int n, int x, int y, int[] arr, int[] brr) {
        // Create an array of Order objects to store tips for each order
        Order[] orders = new Order[n];
        for (int i = 0; i < n; i++) {
            orders[i] = new Order(arr[i], brr[i]);
        }

        // Sort the orders based on the absolute difference between tips from A and B in descending order
        Arrays.sort(orders, new Comparator<Order>() {
            @Override
            public int compare(Order o1, Order o2) {
                return Math.abs(o2.tipA - o2.tipB) - Math.abs(o1.tipA - o1.tipB);
            }
        });

        long totalTips = 0; // To keep track of the total tips collected
        int ordersServedByA = 0; // To count how many orders are served by person A
        int ordersServedByB = 0; // To count how many orders are served by person B

        // Iterate through each order and decide who should serve it to maximize the tips
        for (Order order : orders) {
            // If person A can serve more orders and their tip is higher or equal, or person B has reached their limit
            if ((ordersServedByA < x && order.tipA >= order.tipB) || ordersServedByB >= y) {
                totalTips += order.tipA; // Add tip from person A
                ordersServedByA++; // Increment the count of orders served by A
            } else {
                totalTips += order.tipB; // Add tip from person B
                ordersServedByB++; // Increment the count of orders served by B
            }
        }

        return totalTips; // Return the maximum total tips collected
    }
}

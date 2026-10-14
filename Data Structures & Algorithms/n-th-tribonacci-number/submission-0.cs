public class Solution {
    public int Tribonacci(int n) {
        int[] tribonacci = {0, 1, 1};
   
        for (int i = 3; i <= n; i++) {
            tribonacci[i%3] = tribonacci[0] + tribonacci[1] + tribonacci[2];
        }

        return tribonacci[n%3];
    }
}
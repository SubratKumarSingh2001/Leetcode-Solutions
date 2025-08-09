class Solution {
public:
    int subtractProductAndSum(int n) {
        //TC: O(logn base2), SC: O(1)
        int prod = 1, sum = 0;
        while(n) {
            prod *= n%10;
            sum += n%10;
            n /= 10;
        }
        return prod - sum;
    }
};

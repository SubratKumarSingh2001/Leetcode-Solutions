class Solution {
public:
    int divide(int dividend, int divisor) {
        //Using the Bit Manipulation Concept 

        //Tc: O(logn)^2 (approx), SC: O(1)
        if(dividend == divisor) return 1;
        //if dividend is INT_MIN and divisor is -1
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool sign = true; //represent +ve number
        if(dividend > 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;

        //numerator and denominator
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long q = 0;
        while(n >= d) {
            int pow = 0;
            //pow+1 should be less than 31 because int store 32 bits [0,31] 1<<32 not possible
            while(pow+1 < 31 && d*(1<<(pow+1)) <= n) {
                pow++;
            }
            q += (1<<pow);
            n -= (d*(1<<pow));
        }
        
        return sign ? q : (-1*q);
    }
};

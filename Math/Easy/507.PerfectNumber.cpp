class Solution {
public:
    bool checkPerfectNumber(int num) { 
        //Brute Force, TC: O(n), SC: O(1)
        int sum = 0;
        for(int i=1; i<num; i++) {
            if(num % i == 0) {
                sum += i;
            }
        }
        if(sum == num) return true;
        return false;

        //Optimal Solution: Use Sqrt root function
        /*We can run loop till the square root of n as after that the 
        factor repeats as all the factors can be surely print running loop
        till sqrt(n) because n = i*j we can find the i with the loop and j
        with n/i simultaneously
        */
        //TC: O(sqrt(n)), SC: O(1)
        if(num==1) return false;
        int sum=1;
        for(int i=2; i*i<num; i++) {
            if(num % i == 0) {
                sum = sum + i + num/i;
            }
        }
        if(sum == num) return true;
        return false;
    }
};

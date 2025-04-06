class Solution {
public:
    int bitwiseComplement(int n) {
        //Brute Force: TC: O(logn), SC: O(logn)
        /* when we are playing with digits then we use mod and divide operator 
           combination, because we require the digits instead of bits
        */
        if(n == 0) return 1;
        
        vector<int> ans;
        while(n) {
            if(n == 1) {
                ans.push_back(1-n);
            }
            int rem = n % 2;
            ans.push_back(1-rem);
            n /= 2;
        }

        int sum = 0;
        for(int i=ans.size()-1; i>=0; i--) {
            sum += pow(2,i) * ans[i];
        }
        return sum;

        //Approach:2 Better Space TC: O(logn), SC: O(1)
        /* when we are playing with bits of any number then we use and, or etc
           bitwise operator acc. to the requirement and combination with left or
           right shift operator we we want to move ahead of bits
        */
        if(n == 0)  return 1;
        int ans=0, i=0;
        while(n) {
            int bit = n & 1;
            ans = ans + pow(2,i)*(1-bit);
            n = n >> 1;
            i++;
        }

        return ans;
    }
};

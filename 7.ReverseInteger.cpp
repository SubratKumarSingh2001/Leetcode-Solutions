class Solution {
public:
    int reverse(int x) {
        //TC: O(n), SC: O(1)
        int m = x;
        //if in beginning the value of m is leass than equal to INt_MIN return 0
        if(m <= INT_MIN) {
            return 0;
        }
        if(x < 0) {
            m = -m;
        }  
        int ans = 0;
        while(m) {
            if(ans > INT_MAX/10) {
                return 0;
            }
            int rem = m % 10;
            ans = ans*10 + rem;
            m /= 10;
        }
        
        if(x < 0) return -ans;
        else return ans;
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        //TC: O(n), SC: O(1)
        int cnt=0;
        while(n) {
            int bit = n & 1;
            if(bit != 0) cnt++;
            n = n>>1;
        }
        return cnt;  
    }
};

class Solution {
public:
    int bitwiseComplement(int n) {
        //Brute Force: TC: O(logn), SC: O(logn)
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

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        //brute Force: TC: O(n), SC: O(n)
        vector<int> ans;
        int carry = 0;
        for(int i=num.size()-1; i>=0; i--) {
            int sum = num[i] + k%10 + carry;
            int rem = sum%10;
            ans.push_back(rem);
            k /= 10;
            carry = sum/10; 
        }
        while(k>0 || carry>0) {
            int sum = k%10 + carry;
            int rem = sum%10;
            ans.push_back(rem);
            k /= 10;
            carry = sum/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;   
    }
};

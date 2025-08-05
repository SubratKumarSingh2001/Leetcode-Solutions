class Solution {
public:
    int signFunc(double product) {
        if(product > 0) return 1;
        else if(product < 0) return -1;
        else return 0;
    }

    int arraySign(vector<int>& nums) {
        //TC: O(n), SC: O(1)
        double product = 1;
        for(int i=0; i<nums.size(); i++) {
            product *= nums[i];
        }
        return signFunc(product);
    }
};

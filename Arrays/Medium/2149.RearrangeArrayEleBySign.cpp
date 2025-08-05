class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //Brute Force, TC: O(n)+O(n/2)[while loop as pos==neg] = O(3n/2) = O(n)
        //SC: O(n/2)[pos vector] + O(n/2)[neg vector] + O(n)[ans vector] = O(n+n = 2n= n)
        //storing all positive and negative numbers
        vector<int> pos; vector<int> neg;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) pos.push_back(nums[i]);
            else if(nums[i] < 0) neg.push_back(nums[i]);
        }
        //now we will create an array to store the consecutive pairs
        int i=0, j=0;
        vector<int> ans;
        while(i<pos.size() && j<neg.size()) {
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++; j++;
        }
        return ans;

        //Optimal SOlution, Two Pointers
        //TC: O(n), SC: O(n)
        //we know that positive no will be at even index and negative no at odd index
        int posInd = 0, negInd = 1;
        //we will store ans in another array
        vector<int> ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            //if ele in +ve 
            if(nums[i] > 0) {
                ans[posInd] = nums[i];
                posInd += 2;
            }
            else {
                ans[negInd] = nums[i];
                negInd += 2;
            }
        }
        return ans;
    }
};

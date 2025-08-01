class Solution {
public:
    bool search(vector<int> nums, int ele) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == ele) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        //Brute Force, TC: O(n^2), SC: O(1)
        int i=0;
        int maxCnt=1;
        while(i<nums.size()) {
            int cnt = 1, j=1;
            while(search(nums, nums[i]+j) == true) {
                cnt++;
                j++;
            }
            maxCnt = max(maxCnt, cnt);
            i++;
        }
        return maxCnt;

        //Better Solution: Sorting can be used here 
        //TC: O(nlogn), SC: O(1)
        sort(nums.begin(), nums.end());
        int maxi=1, cnt=1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] - nums[i-1] == 1) cnt++;
            else if(nums[i] == nums[i-1]) continue;
            else cnt = 1; 
            maxi = max(maxi, cnt);
        }
        return maxi;

        // Optimal Solution : Using orderd set
        TC: O(n+logn = n), SC: O(n)
        if(nums.empty()) return 0;
        set<int> s;
        //first we will insert all the unique elements to the set DS
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }

        //now we will check for the longest consecutive sequence
        int maxi=1, cnt=1;
        for(auto it : s) {
            if(s.find(it+1) != s.end()) cnt++;
            else cnt=1;
            maxi = max(maxi, cnt);
        }
        return maxi;

        //Optimal Solution: Using unordered set
        //TC: O(n+n=2n+n==3n = n), SC: O(n)
        if(nums.empty()) return 0;
        unordered_set<int> s;
        //first we will insert the element in the set
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        //now we will find the longest conecutive sequence
        int maxi = 1;
        for(auto it : s) {
            if(s.find(it-1) == s.end()) {
                int x = it;
                int cnt = 1;
                while(s.find(x+1) != s.end()) {
                    x +=1;
                    cnt++;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};

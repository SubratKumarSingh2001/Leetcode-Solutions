class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute Force
        //TC: O(n^3 + log(no.of triplets)), SC: O(2*no.of triplets) 
        //we will take the unordered set to keep unique list of 3 ele whose sum is 0
        set<vector<int>> st; 
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                for(int k=j+1; k<nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        //now we will sort this elemnets bcz set to identify is unique or not
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        //at last i want all the elements of the set in the 2d vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        
        //Better Soluiton : Somewhere reducing TC to O(n^2)
        //TC: O(n^2 + log(no.of triplets)
        //SC: O(2* no.of triplets) + o(n)(for the dupSet which keep at most size of nums in i it)                       
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++) {
            //every time our set containing elements from i to j chamges as we move ahead the i
            set<int> dupSet;
            for(int j=i+1; j<nums.size(); j++) {
                int ele = -(nums[i] + nums[j]);
                if(dupSet.find(ele) == dupSet.end()) {
                    dupSet.insert(nums[j]);
                }
                else {
                    vector<int> temp = {nums[i], nums[j], ele};\
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;

        //Optimal Solution: reducing the space that we are doing sorting & then storing, Use 2-Pointers
        //TC: O(n^2 + nlogn), SC: O(no.of unique triplets)
        vector<vector<int>> ans;
        //array must be sorted
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            //if move ahead with the i and encounterd the same value and i index dont find paper, as it will give same pair
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            //now we will run the loop when j crosses the k as j and k cant be equal too
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) {
                    //means array is sorted and if move ahead the sum will be greater
                    k--;
                }
                else if(sum < 0) {
                    //means array is sorted and if we move ahead of the array means sum value will be becoming +ve
                    j++;
                }
                else {
                    //means sum is equal to the 0
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++; k--; //we are donw with these values
                    //but if currrent j and k pointed to the same value as of the previous value will give same pair
                    while(j<k && nums[j] == nums[j-1]) j++; //do this till the j<k else we will not get sorted
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }

        }
        return ans;
    }
};

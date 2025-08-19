class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //Brute Force, TC: O(n^4 + log(no.of triplets)), SC: O(2*no.of triplets) 
        //follow the process of the 3Sum by creating the set
        // set<vector<int>> st;
        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         for(int k=j+1; k<nums.size(); k++) {
        //             for(int l=k+1; l<nums.size(); l++) {
        //                 if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
        //                     //we got our desired quardruplets
        //                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
        //                     //now we will sort it so that if this pair comes again we ignore it
        //                     sort(temp.begin(), temp.end());
        //                     //now put this vetor into the set we created 
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // //now we put all the elements of the set inside the 2d vector
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;


        //Better Solution, Thinking to reduce the TC to n^3 or something
        //TC: O(n^3 + log(no.of quadruplets)), SC: O(2* no.of quadruplets) + O(n))(dupSet set) 
        // set<vector<int>> st;
        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         set<int> dupSet;
        //         for(int k=j+1; k<nums.size(); k++) {
        //             int ele = target-(nums[i] + nums[j] + nums[k]);
        //             if(dupSet.find(ele) != dupSet.end()) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k], ele};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //             else {
        //                 dupSet.insert(nums[k]);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        //Optimal Solution: Two Pointers Approach
        //TC: O(n^3 + nlogn), SC: O(no.of unique triplets)
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            //if our curr i is same as prv i index value then pair will give same, hence move ahead
            if(i!=0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<nums.size(); j++) {
                //same as i if j is same as its previous value thne pair exist continue j index
                if(j!=i+1 && nums[j] == nums[j-1]) continue;

                //now we will perfrom 2 pointers approach
                int k = j+1, l = nums.size()-1;
                while(k < l) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if(sum > target) {
                        //that means array is sorted we need to shift the l pointer backward
                        l--;
                    }
                    else if(sum < target) {
                        //that means array is sorted we need to shift the k pointer ahead
                        k++;
                    }
                    else if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        //the temp vector is already sorted
                        ans.push_back(temp);
                        k++; l--;
                        //if we get the same value at index k and l as the value was previous we need to move ahead the pointer to avoid the duplicacy
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--; 
                    }
                }
            }
        }
        return ans;
    }
};

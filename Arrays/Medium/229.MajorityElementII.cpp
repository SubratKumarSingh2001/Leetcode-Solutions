class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Brute Force, TC: O(n^2) SC: O(1) 
        //We are sure that the ans array will have atmost 2 elements as n/3 = whatever it can only 2 elements
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int ele = nums[i];
            int cnt = 0;
            //if our ans is empty and if the element encountered is not present in ans then run the loop
            if(ans.empty() || ans.back() != nums[i]) {
                for(int j=i; j<nums.size(); j++) {
                    if(nums[j] == ele) cnt++;
                }
                if(cnt > nums.size()/3) {
                    ans.push_back(ele);
                }
            }
            if(ans.size() == 2) break;
        }
        return ans;

        //Better Soluiton, Using Hashing
        //TC: O(n), SC: O(n)
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;

            //chercking whether to store in ans or not
            if(mp[nums[i]] == nums.size()/3 + 1) {
                ans.push_back(nums[i]);
            }
            //and the answer can have max size of 2
            if(ans.size() == 2) break;
        }
        return ans;

        //Optimal Soluiton, Moore's Voting Algo same as Majority element-I
        //Follow the same intution as Majority Element-I Moores's Voting Algo, This question must have knowledge of Majority ELement-I
        //TC: O(2n), SC: O(1)
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(cnt1 == 0 && ele2 != nums[i]) { //make sure that ele1 holding which nums vaslue must not be hold by ele2 var
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i]) { //make sure that ele2 holding which nums vaslue must not be hold by ele1 var
                cnt2 = 1;
                ele2 = nums[i];
            } 
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }
        //now we have got the possibe majority element i.e ele1 and ele2 but we have to check whether they are actual amjority element
        vector<int> ans;
        cnt1=0, cnt2=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        if(cnt1 > nums.size()/3) ans.push_back(ele1);
        if(cnt2 > nums.size()/3) ans.push_back(ele2);

        return ans;
    }
};

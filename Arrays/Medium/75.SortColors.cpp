class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Brute Force using unbuilt sort function 
        //TC: O(nlogn), SC: O(1)
        sort(nums.begin(), nums.end());

        //Better Approach
        //TC: O(n), SC: O(1)
        /*
        But this is not in-place sort are changing the original array
        */
        int zeros=0, ones=0, twos=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) zeros++;
            else if(nums[i] == 1) ones++;
            else if(nums[i] == 2) twos++;
        }
        int i=0;
        while(zeros) {
            nums[i] = 0;
            i++;
            zeros--;
        }
        while(ones) {
            nums[i] = 1;
            i++;
            ones--;
        }
        while(twos) {
            nums[i] = 2;
            i++;
            twos--;
        }

        //Optimal Solution: Dutch National Flag (3 Pointers Approach)
        //Here every comparison is done with mid pointer and swapped accordingly
        //TC: O(n), SC: O(1)
        int start=0, mid=0, end = nums.size()-1;
        while(mid <= end) {
            if(nums[mid] == 0) {
                swap(nums[start], nums[mid]);
                start++, mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[end]);
                end--;
            }
            else {
                mid++;
            }
        }
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Brute Force :  To find all the permutaion of the given array
        //Check nums[i] > nums[i+1], SC: O(n!*n), SC: O(1)

        // //C++ provide the STL to find the next permuation of the current array we hacve 
        // next_permutation(nums.begin(), nums.end());

        //Optimal Solution:
        /*First we will try to find the longest prefix that will remain same and after that longest
        prefix we will try to shuffle the elements to make just greater element*/

        //TC: O(3n = n), SC: O(1)
        int index = -1;
        for(int i= nums.size()-2; i>=0; i--) {
            if(nums[i+1] > nums[i]) {
                index = i;
                break;
            }
        }

        //could be possible that the there is no next permutation means larger element for that return reverse
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        //perform this when there is only index != -1
        /*Now we will try to find the just greater element than nums[index] from last search*/
        for(int i=nums.size()-1; i>index; i--) {
            if(nums[i] > nums[index])  {
                swap(nums[i], nums[index]);
                break;
            }
        }
        //now we know that the the rest half is the already is increasing order to make it smallest reverse it
        reverse(nums.begin()+index+1, nums.end());
    }
};

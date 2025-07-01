class Solution {
public:
    void reverse(vector<int>& nums, int start, int last) {
        while(start < last) {
            swap(nums[start], nums[last]);
            start++; last--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        //if k is 0 then no rotate
        if(k==0) return;

        //Brute Force: We can create dummy array and store all elements
        //TC: O(n), SC: O(n) #For extra-space taken to insert elements
        /*First: We will insert all the elements whose position has been changed*/
        vector<int> ans;
        k = k % n;
        int end = n-k-1;
        for(int i=end+1; i<n; i++) {
            ans.push_back(nums[i]);
        }
        /*Second: insert all the elements are need to be present as it is*/
        for(int i=0; i<=end; i++) {
            ans.push_back(nums[i]);
        }
        nums = ans; //original array change

        //Optimal Solution : Achive this by reversing the array 
        k = k % n;
        int i=0;
        //first reverse the entire array
        reverse(nums, i, n-1);

        //then we have to reverse the first k element 
        reverse(nums, i, k-1);

        //then we have to reverse the other remianing half
        reverse(nums, k, n-1);
    }
};

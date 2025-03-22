class Solution {
public:
    int search(vector<int> &numbers, int x, int i) {
        int s=0, e=numbers.size()-1;
        int m = s + (e-s)/2;
        while(s <= e) {
            if(numbers[m] == x && i!=m)  return m;
            else if(numbers[m] <= x) s = m+1;
            else e = m-1;
            m = s + (e-s)/2;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        // Two pointers, TC: O(n), SC: O(1)
        int i=0, j=numbers.size()-1;
        while(i<j) {
            if(numbers[i] + numbers[j] == target) {
                return {i+1, j+1};
            }
            /*we wont check numbers[i] < numbers[j] becuase as array is already given 
            sorted to us so obvious that num[i] will be less than nums[j
            */
            else if(numbers[i] + numbers[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return {};

        //Binary Search 
        //TC: O(nlogn), SC: O(1)
        for(int i=0; i<numbers.size(); i++) {
            int diff = target - numbers[i];
            int index = search(numbers, diff, i);
            if(index != -1) {
                return {i+1, index+1};
            }
        }
        return {};
    }
};

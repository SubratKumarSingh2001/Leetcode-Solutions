class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //Optimal Solution, TC: O(logn), SC: O(1)
        int start=0, end=letters.size()-1;
        int mid = start + (end-start)/2;
        char ans = '0';
        while(start <= end) {
            if(letters[mid] == target) {
                start = mid+1;
            }
            else if(letters[mid] > target) {
                ans = letters[mid];
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return ans == '0' ? letters[0] : ans;
    }
};

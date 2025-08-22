class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        //TC: O(n), SC: O(1)
        int cnt=0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]%2 != 0) {
                cnt++;
                if(cnt == 3) return true;
            }
            else if(arr[i]%2 == 0 && cnt != 3) cnt=0;
        }
        return false;
    }
};

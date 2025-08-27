class Solution {
public:
    void reverseString(vector<char>& s) {
        //Brute Force 
        reverse(s.begin(), s.end());

        //Two-Pointers Approach
        //TC; O(n/2 = n), SC: O(1)
        int i=0, j=s.size()-1;
        while(i <= j) {
            swap(s[i], s[j]);
            i++; j--;
        }

        //Another way, with temp variable
        //TC: O(n), SC: O(1)
        for(int i=0; i<s.size()/2; i++) {
            int temp = s[i];
            s[i] = s[s.size()-i-1];
            s[s.size()-i-1] = temp;
        }
    }
};

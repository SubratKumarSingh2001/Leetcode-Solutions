class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Two Pointers Approach, TC: O(n+m), SC: O(1)
        int i=0, j=0;
        while(i<s.length() && j<t.length()) {
            if(s[i] == t[j]) {
                i++; j++;
            }
            else j++;
        }
        if(i == s.length()) return true;
        return false;
    }
};

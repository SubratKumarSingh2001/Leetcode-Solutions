class Solution {
public:
    string finalString(string s) {
    //TC: O(n), SC: O(n)
        string ans = "";
        for(int i=0; i<s.length(); i++) {
            if(i!=0 && s[i] == 'i') {
                reverse(ans.begin(), ans.end());
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};

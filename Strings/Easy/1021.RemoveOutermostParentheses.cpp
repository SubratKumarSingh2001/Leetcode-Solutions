class Solution {
public:
    string removeOuterParentheses(string s) {
        //Optimal Solution, TC: O(n), SC: O(n)
        string ans = "";
        //this count will keep track of each primitive decomposition
        int cnt = 0, j = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            if(cnt == 0) {
                ans += s.substr(j+1, i-j-1);
                j = i+1;
            }
        }
        return ans;
    }
};

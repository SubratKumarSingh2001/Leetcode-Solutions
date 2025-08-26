class Solution {
public:
    int maxDepth(string s) {
        //TC: O(n), SC; O(1)
        int maxDepth=0, depth=0, cnt=0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                cnt++;
                depth = max(depth, cnt);
            }
            else if(s[i] == ')') cnt--;
            if(cnt == 0) {
                maxDepth = max(maxDepth, depth);
                depth=0;
            }
        }
        return maxDepth;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        //TC: O(len(s)), SC: O(1)
        for(int i=0; i<s.length(); i++) {
            //we will rotate every time and check with goal if s and goal equal true
            s = s.substr(1, s.length()-1) + s[0];
            if(s == goal) return true;
        }
        return false;
    }
};

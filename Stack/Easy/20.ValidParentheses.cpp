class Solution {
public:
    bool isValid(string s) {
        //Brute Force, TC: O(n), SC:O(n)
        if(s.length() == 1) return false;
        string ans = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
                ans.push_back(s[i]);
            }
            else {
                if(ans.empty()) return false;

                if((s[i]==')' && ans.back()=='(') || (s[i]=='}' && ans.back()=='{') ||
                (s[i]==']' && ans.back()=='[')) {
                    ans.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        return ans.empty(); //if empty return true else return false

        //Using stack, TC: O(n), SC: O(n)
        stack<char> st;
        unordered_map<char, char> mp;
        mp[')'] = '('; mp[']'] = '['; mp['}'] = '{'; //we have done corroespondiong map
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(mp[s[i]] == st.top()) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

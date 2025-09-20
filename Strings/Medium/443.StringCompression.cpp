class Solution {
public:
    int compress(vector<char>& chars) {
        //Brute Force: Taking an extra string s 
        //TC: O(n), SC: O(n)(because of string s we took)
        int cnt = 1;
        string s = "";
        for(int i=1; i<chars.size(); i++) {
            if(chars[i] == chars[i-1]) {
                cnt++;
            }
            else {
                s += chars[i-1];
                if(cnt > 1) {
                    s += to_string(cnt);
                }
                cnt = 1;
            }
        }
        //last character is not appeneded to the string s
        s += chars[chars.size()-1];
        if(cnt > 1) {
            s += to_string(cnt);
        }

        /*now we will resise the chars array with the string s size because s.length() can be
        greater than chars.size()*/
        chars.resize(s.length());
        for(int i=0; i<s.length(); i++) {
            chars[i] = s[i];
        }
        return chars.size();
    }
};

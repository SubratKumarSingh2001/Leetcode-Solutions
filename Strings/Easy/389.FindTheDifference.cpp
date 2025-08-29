class Solution {
public:
    char findTheDifference(string s, string t) {
        //Optimal Solution, TC: O(n), SC: O(1)
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }
        for(int i=0; i<t.length(); i++) {
            if(mp.find(t[i]) != mp.end()) {
                mp[t[i]]--;
            }
            else {
                mp[t[i]]++;
            }
        }
        for(auto it : mp) {
            if(it.second != 0)  return it.first;
        }
        return '0';
    }
};

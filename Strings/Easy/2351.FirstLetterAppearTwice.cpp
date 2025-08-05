class Solution {
public:
    char repeatedCharacter(string s) {
        //Optimal Soluiton: Hashing
        //TC: O(n), SC: O(n)
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
            if(mp[s[i]] == 2) return s[i];
        }   
        return -1;
    }
};

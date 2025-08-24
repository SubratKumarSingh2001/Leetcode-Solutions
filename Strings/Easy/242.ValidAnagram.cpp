class Solution {
public:
    bool isAnagram(string s, string t) {
        //Brute Force, TC: O(nlogn), SC: O(1)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        return false;

        //Optimal Solution, TC: O(n+m), SC: O(k) k: no.of unioque characters i.e O(1) equivalent
        //In anagram the frequency of each character in string s and t will be same
        //So if we increment all char in s string and decrement all char is t, and if anagram the freq of each char will be 0
        unordered_map<char, int> mp;
        //increment each character in s string
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }
        //decrement each character in t string
        for(int i=0; i<t.length(); i++) {
            mp[t[i]]--;
        }
        //now check whether the frequency of each ccharacter is 0 or not yes anagram if +ve or -ve not anagram
        for(auto it: mp) {
            if(it.second != 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool checkIfPangram(string sentence) {
        //Brute force, TC:O(n), SC: O(1)
        vector<int> ans(26, 0);
        for(int i=0; i<sentence.length(); i++) {
            ans[sentence[i] - 'a']++;
        }
        for(int i=0; i<26; i++) {
            if(ans[i] == 0) return false;
        }
        return true;

        //Using unordered_se, TC: O(n), SC: O(1)
        unordered_set<int> s;
        for(int i=0; i<sentence.length(); i++) {
            s.insert(sentence[i]); //unique element only inserted
        }
        if(s.size() == 26) return true;
        return false;
    }
};

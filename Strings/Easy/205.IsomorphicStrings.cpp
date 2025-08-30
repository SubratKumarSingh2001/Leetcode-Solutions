class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //Optimal Solution, TC: O(len(s)), SC: O(n)
        int i=0;
        unordered_map<char, char> mp1, mp2;
        while(i<s.length()) {
            //mp1 mapping from s->t
            /*there may be case 2 or more same char trying to map with different char
            like a->x and a->y*/
            if(mp1.find(s[i]) == mp1.end()) {
                mp1[s[i]] = t[i]; 
            }
            else if(mp1[s[i]] != t[i]) return false;

            //mp2 mapping from t->s
            /*there may be case 2 or more same char trying to map with different char
            like a->x and a->y*/
            if(mp2.find(t[i]) == mp2.end()) {
                mp2[t[i]] = s[i];
            } 
            else if(mp2[t[i]] != s[i]) return false;
            i++;
        }
        return true;
    }
};

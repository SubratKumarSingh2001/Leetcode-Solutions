class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Brute Force, TC: O(n*m) because a outer loop can have size equal to size of vector and inner from 1-size
        //SC: O(1)
        int len = strs[0].length(), i=0;
        string ans = "";
        while(i < len) {
            char ch = strs[0][i];
            int j=1;
            for(; j<strs.size(); j++) {
                if(strs[j][i] != ch || strs[j].length() <= i) break;
            }
            if(j == strs.size()) { //complete traverse means ch is common in every string
                ans += ch;
            }
            else {
                break;
            }
            i++;
        }
        return ans;

        //Optimal Solution, TC: O(n), SC: O(1)
        //First we will sort the array lexographical order means alphabet order of each alphabet
        sort(strs.begin(), strs.end());
        //we will evaluate the length of first and last string of vector
        int len1 = strs[0].length(), len2 = strs[strs.size()-1].length();
        string ans = "";
        for(int i=0; i<min(len1, len2); i++) {
            /*Now we will check whether each character of first and last string after sort is same or not if
            same add it into the ans string and if not break and return the ans string, as the last string is 
            sorted in the ascending order of each character so if we have found the common prefix then that
            common prefix will be also same for all the strings leaving first and last strings*/
            if(strs[0][i] == strs[strs.size()-1][i]) {
                ans += strs[0][i];
            }
            else {
                break;
            }
        }
        return ans;
    }
};

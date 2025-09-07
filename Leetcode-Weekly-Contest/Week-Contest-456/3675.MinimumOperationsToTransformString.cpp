class Solution {
public:
    int minOperations(string s) {
        //Brute Force, TC: O(n*k) where k is no.of time for while(true) runs. SC: O(1)
        int cnt = 0;
        while(true) {
            //to check whether all the characters are 'a' or not                                                                            
            bool allA = true;
            for(int i=0; i<s.length(); i++) {
                if(s[i] != 'a') {
                    allA = false; break;
                }
            }
            //now if all characters are a means we have found the minimum break
            if(allA) break;

            //now we will increment each character by one if it is not one
            int i=0;
            for(int i=0; i<s.length(); i++) {
                if(s[i] != 'a') {
                    if(s[i] == 'z') {
                        s[i] = 'a';
                    }
                    else {
                        s[i] = s[i] + 1; // to increment each character
                    }
                }
            }
            //now we will increment with the no. of form 'a'
            cnt++;
        }
        return cnt;

        //Optimal Solution, TC: O(n), SC: O(1)
        int cnt = 0;
        for(int i=0; i<s.length(); i++) {
            //way to convert the ASCII value in the range of [1,26] corr. number
            int step = ('a' - s[i] + 26) % 26;
            cnt = max(step, cnt);
        }
        return cnt;
    }
};

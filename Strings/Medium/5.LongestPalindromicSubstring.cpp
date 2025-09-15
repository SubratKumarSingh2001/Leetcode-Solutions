class Solution {
public:
    bool checkPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++; j--;
            }
            else return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        // //Brute Force, We will find all psossible substrings and check whether that is palindrome or not
        // //TC: O(n^2 + n), SC: O(n)
        // string ans = "";
        // int prevCnt = 0;
        // for(int i=0; i<s.length(); i++) {
        //     for(int j=i; j<s.length(); j++) {
        //         //this will check for the substring is palindrom eor not
        //         if(checkPalindrome(s, i, j)) {
        //             int cnt = j-i+1;
        //             if(cnt > prevCnt) {
        //                 ans = s.substr(i, cnt);
        //                 prevCnt = cnt;
        //             }
        //         }
        //     }
        // }
        // return ans;

        //Optimal Solution, TC: O(n(outer loop)*n(no.of expansion))  SC: O(n)
        if(s.length() == 1) return s;
        string ans = "";
        int cnt = 0;
        for(int i=0; i<s.length(); i++) {
            //if the string length is odd, then middle will point to same index, means 
            int left = i;
            int right = i;
            while(s[left] == s[right]) {
                left--; right++;
                //but if left and right goes index out of bound break
                if(left < 0  || right > s.length()) break;
            }
            if(right-left-1 > cnt) {
                ans = s.substr(left+1, right-left-1);
                cnt = right-left-1;
            }

            //for even length of the string there will be two mid i and i+1 like 'cbbd' here 'bb' is longest not only 'b'
            left = i;
            right = i+1;
            while(right < s.length() && s[left] == s[right]) {
                left--; right++;
                if(left < 0) break;
            }
            if(right-left-1 > cnt) {
                ans = s.substr(left+1, right-left-1);
                cnt = right-left-1;
            }
        }
        return ans;
    }
};

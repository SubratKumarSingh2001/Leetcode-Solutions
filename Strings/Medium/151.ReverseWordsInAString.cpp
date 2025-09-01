class Solution {
public:
    string reverseWords(string s) {
        //Brute Force, taking an extra ans string
        //TC: O(n), SC: O(n)
        string ans = "";
        int cnt = 0;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == ' ' && cnt == 0) continue;
            else if(s[i] != ' ') cnt++;
            else {
                if(!ans.empty()) {
                    ans += ' ';
                }
                ans += s.substr(i+1, cnt);
                cnt=0;
            }
        }
        if(cnt > 0) {
            if(!ans.empty()) {
                ans += ' ';
            }
            ans += s.substr(0, cnt);
        }
        return ans;

        //Optimal Solution, Reducing the Space, TC: O(n), SC: O(1)
        //first we will reverse the entire string so that it would be easy to form reverse string
        reverse(s.begin(), s.end());
        int i=0, j=0, k=0;
        while(i < s.length()) {
            //if leading spaces
            while(i < s.length() && s[i] == ' ') i++;
            
            //if not spaces
            while(i < s.length() && s[i] != ' ') {
                s[j++] = s[i++];
            }

            //now we will reverse the substring to form original substring from end
            reverse(s.begin()+k , s.begin()+j);

            //after reverse move ahead i till we have spaces, once no space and i<length we will then update j and k else we wont add any space 
            while (i < s.length() && s[i] == ' ') i++;

            //now add the space only when above while loop tell hey ith index is still a word and i<len means add a space and update j and k pointer
            if(i < s.length()) {
                s[j++] = ' ';
                k = j;
            }
        }
        return s.substr(0, j);
    }
};

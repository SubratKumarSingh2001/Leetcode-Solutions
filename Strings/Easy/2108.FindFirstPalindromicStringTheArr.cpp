class Solution {
public:
    bool checkPalindrome(string word) {
        int i=0, j=word.length()-1;
        while(i <= j) {
            if(word[i] != word[j]) return false;
            i++; j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        //Palindrome check for each words[i], TC: O(n*k/2) = O(n*k) where k: is len(words[i])
        //SC: O(1)
        for(int i=0; i<words.size(); i++) {
            if(checkPalindrome(words[i])) return words[i];
        }
        return "";

        //Can do by reversing each string i.e words[i] and check if equals return true else return false
    }
};

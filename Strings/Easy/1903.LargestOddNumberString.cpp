class Solution {
public:
    string largestOddNumber(string num) {
        //Optimal Solution, TC; O(n), SC: O(1)
        string s = "";
        int index = -1;
        for(int i=num.length()-1; i>=0; i--) {
            if(((int)num[i])%2 !=0) {
                index = i;
                break;
            }  
        }
        if(index == -1) return "";
        for(int i=0; i<=index; i++) {
            s.push_back(num[i]);
        }
        return s;
    }
};

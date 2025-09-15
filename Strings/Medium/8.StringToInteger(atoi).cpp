class Solution {
public:
    int myAtoi(string s) {
        //TC: O(n(spaces)+n(while loop traversal)), SC: O(n)
        //first we will keep the track of leading spaces and if number will be -ve or +ve
        int i=0, sign=1; //which tell whether the number is +ve or -ve 
        while(i<s.length() && s[i] == ' ') {
            i++;
        }
        //once all the leading spaces covered there will be either '-'sign or no sign
        if(s[i] == '-') {
            sign = -1; i++;
        }
        else if(s[i] == '+') {
            i++;
        }
        //now we wll find the number 
        long long ans = 0;
        while(i<s.length() && isdigit(s[i])) {
            ans = sign * (ans * 10 + s[i] - '0');
            //to check for the 32-bit signed integer, if ans if samller than INT_MIN/10
            if(ans < INT_MIN) return INT_MIN;
            //if ans is greater than the INT_MAX/10
            else if(ans > INT_MAX) return INT_MAX;
            ans = sign * ans;
            i++;
        }
        return sign*ans;
    }
};

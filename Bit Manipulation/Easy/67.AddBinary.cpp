class Solution {
public:
    string addBinary(string a, string b) {
        //TC: O(n+m), SC: O(max(m,n))
        string ans = "";
        int i= a.length()-1, j = b.length()-1;
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int sum = (a[i]-'0') + (b[j]-'0') + carry;
            int rem = sum & 1;
            carry = sum >> 1;
            ans += to_string(rem);
            i--; j--;
        }
        while(j >= 0) {
            int sum = (b[j]-'0') + carry;
            int rem = sum & 1;
            carry = sum >> 1;;
            ans += to_string(rem);
            j--;
        }
        while(i >= 0) {
            int sum = (a[i]-'0') + carry;
            int rem = sum & 1;
            carry = sum >> 1;;
            ans += to_string(rem);
            i--;
        }
        if(carry) {
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

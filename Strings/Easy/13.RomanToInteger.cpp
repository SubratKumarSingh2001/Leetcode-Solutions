class Solution {
public:
    int romanToInt(string s) {
        //One way, TC: O(n), SC: O(1)
        unordered_map<char, int> mp1 = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, 
        {'D',500}, {'M',1000}};
        unordered_map<string, int> mp2 = {{"CM",900}, {"CD",400}, {"XL",40}, {"XC",90}, 
        {"IV",4}, {"IX",9}};
        int i=0, sum=0;
        while(i < s.length()) {
            if(mp2.find(s.substr(i,2)) != mp2.end()) {
                sum += mp2[s.substr(i,2)];
                i += 2;
            }
            else {
                sum += mp1[s[i]];
                i++;
            } 
        }
        return sum;
    }
};

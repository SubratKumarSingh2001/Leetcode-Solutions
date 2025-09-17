class Solution {
public:
    int beautySum(string s) {
        //Brute Force, O(n^2) here maxi and mini we are finding on fixed length of 26, SC: O(1)
        vector<int> alpha(26, 0);
        int sum = 0;
        for(int i=0; i<s.length(); i++) {
            for(int j=i; j<s.length(); j++) {
                char ch = s[j];  
                alpha[ch - 'a']++;
                int maxi = *max_element(alpha.begin(), alpha.end());
                int mini = INT_MAX;
                for(auto x : alpha) {
                    if(x > 0) mini = min(mini, x);
                }
                sum += (maxi - mini);
            }
            for(int k=0; k<26; k++) {
                alpha[k] = 0;
            }
        }
        return sum;

        //Optimal Solution, Using Hashmap + Prefix Sum
        //TC: O(n^2) Best because 1<=n<=500 if n max value given to 10^5 then O(n) we have to think
        //SC: O(1)
        unordered_map<char, int> mp;
        int sum = 0;
        for(int i=0; i<s.length(); i++) {
            //for every nested iteration we want the mp should be empty
            mp.clear();
            for(int j=i; j<s.length(); j++) {
                mp[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                // to find the max and min frequency of character from the map
                for(auto it : mp) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};

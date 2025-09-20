class Solution {
public:
    string reorganizeString(string s) {
        //TC: O(n + klogk(where k is the no.of unique characters)), SC: O(k)
        //first we will find the freqency of each element and store in hash
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }
        //we will try to do it with priority queue
        priority_queue<pair<int, char>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        //now i will take the top element of pq which is of max frequeny
        pair<int, char> p = pq.top();
        int maxi = p.first;
        char ch = p.second;

        //now check whether the max frequency element is able or insert at pos, pos+1, pos+2..
        int index = 0;
        string ans(s.length(), '0');
        while(index < s.length() && maxi--) {
            ans[index] = ch;
            index += 2;
        }
        //if max frequency ele still left return empty string
        if(maxi > 0) return "";

        pq.pop(); //we have print the element with max frequency   
        //now we will print the remaning elements
        index = 1;
        while(index < s.length()) {
            if(ans[index] != ch) {
                pair<int, char> p = pq.top();
                pq.pop(); //once access got of top remove
                int cnt = p.first;
                char ch1 = p.second;
                ans[index] = ch1;
                cnt--;
                //now if the cnt still remains push it into pq
                if(cnt > 0) pq.push({cnt, ch1});   
            }
            index++;
        }
        return ans;
    }
};

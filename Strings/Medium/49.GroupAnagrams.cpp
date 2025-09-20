class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //TC: O(n*klogk), SC: O(n*k)
        //create a map and store the sorted string as a key and empty vector as value to push ele later
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if(mp.find(str) == mp.end()) {
                mp[str];
            }
            //if key is not present the above will create the key and then insert string inside the key
            mp[str].push_back(strs[i]);
        }
        //now we need to push the each vector value of the key inside the 2d vector
        vector<vector<string>> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

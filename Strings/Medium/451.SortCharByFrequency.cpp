class Solution {
public:
    string frequencySort(string s) {
        //One way
        //Brute Force, TC: O(k^2+n) where k is no.of unique char = O(n^2), SC: O(n)
        //first we will insert the character and its frequency in the map
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }

        //now we will find the sort characters with frequency
        string ans = "";
        while(true) {
            if(mp.empty()) break;

            int maxi = INT_MIN;
            char ch = '0';
            //traverse inside the map
            for(auto it : mp) {
                if(it.second > maxi) {
                    ch = it.first;
                    maxi = it.second;
                }
            }
            //once loop over now insert it into ans string
            ans.append(maxi, ch); //append(cnt, character) .append() insert character in ans cnt no.of times
            //now remove that key from map
            mp.erase(ch);
        }
        return ans;

        //Using priority queue
        /*PRIORITY QUEUE it is different from the normal queue which store and remove elements in FIFO order but 
        priority queue is by default max-heap and we can also make in min-heap. Max-Heap means the root element
        or top element will be always the largest element rest element can be of any order and if we pop the largest 
        element the next largest element will be our root/top element. in this way we can store the frequency
        of each character along with the character in the priority quue and it is sure that the top element of pq
        will be the largest element*/

        //Second Way 
        //TC: O(n+klogk) where k are number of unique elements, SC: O(n)
        //take a map and insert the element and frequency in it
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }

        //now create the priority queue stl, it takes one input, here we have taken the pair(int, char)
        priority_queue<pair<int, char>> pq;
        for(auto it : mp) {
            //now pr top/root element will be character with largest frequency due to max-heap
            pq.push({it.second, it.first});
        }

        string ans = "";
        //now traverse inside the priority queue
        while(!pq.empty()) {
            pair<int, char> p = pq.top(); //because top element have character with highest frequency
            int cnt = p.first;
            char ch = p.second;
            //now insert the character cnt number of times in ans string
            ans.append(cnt, ch);
            //pop the top element from the pq, now the next largest element will be at top
            pq.pop();
        }
        return ans;
    }

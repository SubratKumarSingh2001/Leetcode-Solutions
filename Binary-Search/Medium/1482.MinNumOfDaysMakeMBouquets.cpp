class Solution {
public:
    int possibleDay(vector<int>& bloomDay, int m, int k, int day) {
        int cnt=0, bouquet=0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                cnt++;
            }
            else {
                bouquet += cnt/k;
                cnt=0;
            }
        }
        bouquet += cnt/k;
        
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //Brute Force, TC: O((max(arr)-min(arr)+1)*n), SC: O(1)
        int n = bloomDay.size();
        long long product = k*m;
        if(product > n) return -1;

        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        for(int i=min; i<=max; i++) {
            int cnt=0, bouquet=0;;  
            for(int j=0; j<n; j++) {
                if(bloomDay[j] <= i) {
                    cnt++;
                }
                else {
                    bouquet += cnt/k;
                    cnt=0;
                }
            }
            //it was used to count the last batch of the bouquet that need to be added
            bouquet += cnt/k;
            /*if bouquet are more or equal to m then return that day, for less value of
            of bouquets compare to m as we cant make m no.of bouquet check another day
            as there is atleast 1 day 
            */
            if(bouquet >= m) {
                return i;
            }
        }
        return -1;

        //Optimal Solution, Binary Search
        //TC: O(log(max(arr)-min(arr))*n), SC: O(1)
        int n = bloomDay.size();
        long long totalFlower = (long long)m*k;
        if(totalFlower > n)  return -1;
        //to find the min and max value of an array.
        int min = INT_MAX, max = INT_MIN;
        for(int i=0; i<n; i++) {
            if(max < bloomDay[i]) {
                max = bloomDay[i];
            }
            if(bloomDay[i] < min) {
                min = bloomDay[i];
            }
        }
        int start=min, end=max;
        int day = start + (end-start)/2;
        int possDay = -1;
        while(start <= end) {
            if(possibleDay(bloomDay, m, k, day) >= m) {
                possDay = day;
                end = day-1;
            }
            else{
               start = day+1;
            }
            day = start + (end-start)/2;
        }
        return possDay;
    }
};

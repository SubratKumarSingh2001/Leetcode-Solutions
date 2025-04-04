class Solution {
public:
    int possible(vector<int>& weights, int possWeight) {
        int totalDays=0, currWeight = possWeight;
        int i=0;
        while(i < weights.size()) {
            if(currWeight >= weights[i]) {
                currWeight -= weights[i];
                i++;
            }
            else {
                totalDays++;
                currWeight = possWeight;
            }
        }
        /*when we come out of the loop we have to add up the last updated totalDay,
        as we ended loop before adding up the another totalDay, so therefore we are 
        incrmenting the totalDay
         */
        totalDays++;
        // if(totalDays <= days) return true;

        // return false;

        return totalDays;
    }

    int minVal(vector<int>& weights) {
        int min = INT_MIN;
        for(int i=0; i<weights.size(); i++) {
            if(weights[i] > min) {
                min = weights[i];
            }
        }
        return min;
    }

    int maxVal(vector<int>& weights) {
        int max = 0;
        for(int i=0; i<weights.size(); i++) {
            max += weights[i];
        }
        return max;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //Brute Force
        //TC: O((max(weight)-min(weight)+1)*n), SC: O(1)
        // int min = minVal(weights); // min value of weight will be max value of an array
        // int max = maVal(weights); // max value of weight will be sum of all weight of array
        // for(int i=0; i<weights.size(); i++) {
        //     if(possible(weigths, i, days)) {
        //         return i;
        //     }
        // }
        // return -1;

        //optimal Approach, Binaraay Search
        //TC: O(log(max(weight)-min(weight)+1)*n)), SC: O(1)
        int min = minVal(weights); // min value of weight will be max value of an array
        int max = maxVal(weights); // max value of weight will be sum of all weight of array
        int start=min, end=max;
        int mid = start + (end-start)/2;
        int weight = -1;
        while(start <= end) {
            if(possible(weights, mid) <= days) {
                weight = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return weight;
    }
};

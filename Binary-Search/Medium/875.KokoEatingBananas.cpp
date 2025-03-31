class Solution {
public:
    int maxEle(vector<int>& piles) {
        int max = INT_MIN;
        for(int i=0; i<piles.size(); i++) {
            if(piles[i] > max) {
                max = piles[i];
            }
        }
        return max;
    }
    long long totalEatingTime(vector<int>& piles, int potValueOfK) {
        long long totalTime = 0;
        for(int i=0; i<piles.size(); i++) {
            totalTime += ceil((double)piles[i]/potValueOfK);
        }
        
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        /*Binary Search- Search Space Pattern for k can be from 1 to max ele of array*/ 
        //TC: O(n*log(maxEle)), SC: O(1)
        int start = 1, end= maxEle(piles);
        int potValueOfK = start + (end-start)/2;
        int k = -1;
        while(start <= end) {
            if(totalEatingTime(piles, potValueOfK) <= h) {
                k = potValueOfK;
                end  = potValueOfK-1;
            }
            else if(totalEatingTime(piles, potValueOfK) > h) {
                start = potValueOfK+1; 
            }
            potValueOfK = start + (end-start)/2;
        }
        return k;
    }
};

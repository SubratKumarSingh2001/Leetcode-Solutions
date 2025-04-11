int canCowsPlaced(vector<int>& stalls, int possMaxVal) {
    int currCow = 1, cowPlacedAt = stalls[0];
    for(int i=1; i<stalls.size(); i++) {
        if((stalls[i] - cowPlacedAt) >= possMaxVal) {
            currCow++;
            cowPlacedAt = stalls[i];
        }
    }
    return currCow;
}

int aggressiveCows(vector<int> &stalls, int k) {
    //    Write your code here.
    //Brute Force, TC: O(n*(max-min)), TC: O(1)
    int min = *min_element(stalls.begin(), stalls.end());
    int max = *max_element(stalls.begin(), stalls.end());
    sort(stalls.begin(), stalls.end());
    // for(int i=1; i<=max-min+1; i++) {
    //     if(canCowsPlaced(stalls, i, k)) continue;
    //     else return (i-1);
    // }
    // return -1;

    //Optimal Solution, Binary Search
    //TC: O(n*log(max-min)), SC: O(1)
    int start=1; int end = max-min+1;
    int mid = start + (end-start)/2;
    int possMax = -1;
    while(start <= end) {
        if(canCowsPlaced(stalls, mid) >= k) {
            possMax = mid;
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return possMax;
}

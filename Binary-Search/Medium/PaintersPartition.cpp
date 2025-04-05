int possible(vector<int>& boards, int currTime) {
    int sum=0, possTime=0;
    int i=0; 
    while(i < boards.size()) {
        if(sum+boards[i] <= currTime) {
            sum += boards[i];
            i++;
        }
        else {
            possTime++;
            sum=0;
        }
    }
    /*we have to update the last value of possValM beacuse before 
    adding up the last value we have ended the loop
    */
    possTime++;
    // if(possTime <= painter){
    //     return true;
    // }
    // return false; 

    return possTime;
}

int sumVal(vector<int>& boards) {
    int sum=0;
    for(int i=0; i<boards.size(); i++) {
        sum += boards[i];
    }
    return sum;
}



int findLargestMinDistance(vector<int> &boards, int k) {
    //    Write your code here.
    //Brute Force, TC:O((max-min+1)*n) , SC: O(1)
    /*This problem is same as Container to Ship Packages within D
    Days and Book Allocation
    */ 
    /*min time will be equal to the max length value in the array
    board because if k == size then min time will max val of array 
    board
    */
    int min = *max_element(boards.begin(), boards.end());
    /*max time will be sum of all length of board of array when k==1 
    then a single painter has to paint all the baords so being taken
    1 unit of time the min 
    */
    int max = sumVal(boards);
    // for(int i=min; i<=max; i++) {
    //     if(possible(boards, i, k)) {
    //         return i;
    //     }
    // } 
    // return -1;

    //Optimal Solution, Binary Search
    //TC: O(log(max-min+1)*n), SC: O(1)
    int start=min, end=max;
    int mid = start + (end-start)/2;
    int time = -1;
    while(start <= end) {
        if(possible(boards, mid) <= k) {
            time = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return time;
}

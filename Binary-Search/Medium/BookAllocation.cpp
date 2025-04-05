int possible(vector<int>& arr, int currValM) {
    int sum=0, possValM=0;
    int i=0; 
    while(i < arr.size()) {
        if(sum+arr[i] <= currValM) {
            sum += arr[i];
            i++;
        }
        else {
            possValM++;
            sum=0;
        }
    }
    /*we have to update the last value of possValM beacuse before 
    adding up the last value we have ended the loop
    */
    possValM++;
    // if(possValM <= m){
    //     return true;
    // }
    // return false; 

    return possValM++;
}

int sumVal(vector<int>& arr) {
    int sum=0;
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    //Brute Force, TC:O((max-min+1)*n) , SC: O(1)
    /*This problem is same as Container to Ship Packages within D
    Days
    */ 
    if(m > arr.size()) return -1;
    /*min pages will be equal to the max value of an array because if
    m == size then min pages will be same i.e max val of array
    */
    int min = *max_element(arr.begin(), arr.end());
    /*max pages will be sum of all pages of array when m==1 and the
    min pages will be sum of all pages as the single student must 
    be allocated all the books  
    */
    int max = sumVal(arr);
    for(int i=min; i<=max; i++) {
        if(possible(arr, i, m)) {
            return i;
        }
    } 
    return -1;

    //Optimal Solution, Binary Search
    //TC: O(log(max-min+1)*n), SC: O(1)
    int start=min, end=max;
    int mid = start + (end-start)/2;
    int pages = -1;
    while(start <= end) {
        if(possible(arr, mid) <= m) {
            pages = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return pages;

}

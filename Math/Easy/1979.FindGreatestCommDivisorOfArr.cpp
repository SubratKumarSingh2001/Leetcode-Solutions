class Solution {
public:
    int findGCD(vector<int>& nums) {
        //Brute Force
        //TC: O(2n+small)=O(n+min(small, large))[when we dontknow which is small or large]
        //SC: O(1)
        int small = *min_element(nums.begin(), nums.end());
        int large = *max_element(nums.begin(), nums.end());
        int gcd = -1;
        for(int i=1; i<=small; i++) {
            if((small % i == 0) && (large % i == 0)) {
                /*We can use gcd = max(gcd, i) but gcd value will change till it satisfies
                the if-condition so the last stored vaue in gcd varibale will be the 
                largest +ve number that divides the small and large.
                Hence we wrote gcd = i 
                */
                gcd = i; 
            }
        } 
        return gcd;  

        //Optimal Solution: Euclidean Algorithm
        /*The Euclidean Alog states that gcd(a,b) = gcd(a-b,b) if a>b, do this until
        either of a or b become 0 then the non zero number will be the gcd of a and b
        */
        //TC: O(2n + logx min(a,b)), SC: O(1)
        int a = small, b = large;
        while(a>0 && b>0) {
            if(a > b) {
                a = a % b;
            }
            else {
                b = b % a;
            }
        }
        //now either of a or b become 0
        if(a == 0) return b;
        return a;
    }
};

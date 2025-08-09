class Solution {
public:
    int differenceOfSums(int n, int m) {
        //TC: O(n), SC: O(1)
        int num1=0, num2=0;
        for(int i=1; i<=n; i++) {
            if(i%m != 0) num1 += i;
            else if(i%m == 0) num2 += i;
        }
        return num1-num2;

        //Better Time complexity, TC: O(1), SC: O(1)
        int totalSum = n*(n+1)/2;
        int totalDiv = (m * (n/m) * ((n/m)+1))/2;
        return (totalSum - totalDiv) - totalDiv;
    }
};                                                                                             

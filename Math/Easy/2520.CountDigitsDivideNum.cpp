class Solution {
public:
    int countDigits(int num) {
        //TC: O(logn), SC: O(1)
        int cnt=0;
        int number = num;
        while(number) {
            int val = number % 10;
            if(num % val == 0) cnt++;
            number /= 10;
        }
        return cnt;
    }
};

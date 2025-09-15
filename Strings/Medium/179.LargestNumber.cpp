class Solution {
public:
    //Good Question 
    /*now the comparator is declared inside the class Solution so to access it we require the
    object of the class Soution like Solution s s.cmp(a, b) but the sort function accept the
    comparator in the form of bool cmp(int a, int b) means if this method is declared 
    outside the class it would be easily accessed, to make this method as a normal method we
    declared it a static method (static means which is shared among every instanc of class
    Now it act a normal method declared inside the class namespace*/
    static bool cmp(int a, int b) {
        /*now we want the comparator to swap the element on the basis of a+b and b+a, if a+b
        is greater than b+a then a+b should come first or if b+a is greater than a+b means
        return false means need to do swap*/
        string t1 = to_string(a);
        string t2 = to_string(b);
        return t1+t2 > t2+t1; //descedning order sort
    }

    string largestNumber(vector<int>& nums) {
        //cmp return true or false swapping should be done or not it is handled by sort()
        sort(nums.begin(), nums.end(), cmp); //cmp is custom comparator
        string ans = "";
        for(int i=0; i<nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        //if all 0 return 0
        if(nums[0] == 0) return "0";
        return ans;
    }
};

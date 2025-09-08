class Solution {
public:
    string convert(string s, int numRows) {
        //edge case if string length is 1 or numRows is 1 then that case it will form the original array
        if(s.length() == 1 || numRows == 1) return s;
        /*For each row we will will be going down to some places and then up to some places*/

        //now we will loop till entire string and print entire row
        string ans = "";

        //The outer loop will run for the no.of rows provided to us
        for(int i=0; i<numRows; i++) {
            //Each row first index will be inserted in the new string, so we need to hold that
            int idx = i;
            //Now find the number of element we need to skip at down with resp to element at idx index
            int down = 2*(numRows-i-1);
            //Same find the number of element we need to skip at up with resp to element at idx index
            int up = 2*i;

            bool downGoing = true; // for each element go down & up some no. of times
            while(idx < s.length()) {
                //THis will help us in inserting 'idx' index element at each new ans string
                ans += s[idx];

                //if the row is 0 then we will be only going down 
                if(i == 0) {
                    idx += down;
                }
                //if the row is last means we are going up always
                else if(i == numRows-1) {
                    idx += up;
                }

                //now for element at row other than 0 or last, then we will first go down & then up
                else {
                    if(downGoing) {
                        idx += down;
                    }
                    else {
                        //going up 
                        idx += up;
                    }
                    //We are dong toggle because for rows 1-rows-2 we need to toggle down->up->down->up.... and so on
                    downGoing = !downGoing;
                }
            }
        }
        return ans;
    }
};

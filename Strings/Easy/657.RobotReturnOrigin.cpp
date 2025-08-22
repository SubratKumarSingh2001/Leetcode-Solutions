class Solution {
public:
    bool judgeCircle(string moves) {
        //TC: O(n), SC: O(1)
        vector<int> res{0,0};
        for(int i=0; i<moves.length(); i++) {
            if(moves[i] == 'U') {
                res[1]++;
            }
            else if(moves[i] == 'D') {
                res[1]--;
            }
            else if(moves[i] == 'L') {
                res[0]++;
            }
            else {
                res[0]--;
            }
        }
        if(res[0] == 0 && res[1] == 0) return true;
        return false;
    }
};

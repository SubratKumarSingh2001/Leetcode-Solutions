class Solution {
public:
    int calPoints(vector<string>& operations) {
        //TC: O(n), SC: O(n)
        stack<int> st;
        for(int i=0; i<operations.size(); i++) {
            if(operations[i] == "C") {
                st.pop();
            }
            else if(operations[i] == "D") {
                st.push(2*st.top());
            }
            else if(operations[i] == "+") {
                //we need to add only top 2 elements
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1); //first push original top 
                st.push(top1 + top2); //and then push the sum of top 2 elements
            }
            else {
                st.push(stoi(operations[i])); //stoi convert string to integer
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int>st;
        for(int i = 0;i<n;i++){
            if(operations[i]== "C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int ans1;
                ans1 = st.top()*2;
                st.push(ans1);
            }
            else if(operations[i] == "+"){
                int ans,ans1;
                ans = st.top();
                st.pop();
                ans1 = ans+st.top();
                st.push(ans);
                st.push(ans1);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
    for( auto &a :asteroids){
        while(!st.empty() && a<0 && st.top()>0){
            int sum = a + st.top();
            if(sum<0){
                st.pop();
            }
            else if(sum>0){
                a =0;
            }
            else{
                st.pop();
                a= 0;               
            }
        }
        if(a != 0){
            st.push(a);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
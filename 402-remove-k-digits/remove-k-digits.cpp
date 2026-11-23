class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int count = 0;

        for (char c : num) {
            while (!st.empty() && st.top() > c && count < k) {
                st.pop();
                count++;
            }
            st.push(c);
        }

        // Remove remaining digits from the end if count < k
        while (!st.empty() && count < k) {
            st.pop();
            count++;
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Strip leading zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        ans = ans.substr(start);

        return ans.empty() ? "0" : ans;
    }
};

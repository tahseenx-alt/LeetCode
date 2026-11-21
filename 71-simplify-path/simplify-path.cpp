class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                continue;
            }
            string token = "";
            while (i < path.size() && path[i] != '/') {
                token += path[i];
                i++;
            }
            if (token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            }
            else {
                st.push_back(token);
            }
        }
        string ans = "";
        for (int i = 0; i < st.size(); i++) {
            ans += "/" + st[i]; 
        }
        return ans.empty() ? "/" : ans; 
    }
};

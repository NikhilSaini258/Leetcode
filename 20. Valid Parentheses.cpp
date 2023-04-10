class Solution {
public:
    unordered_map<char, int> um = {{'(', -1}, {'[', -2}, {'{', -3}, {')', 1}, {']', 2}, {'}', 3}, };
    bool isValid(string s) {
        stack<char> st;  // To store sequence of parentheses
        for (auto& c: s) {
            if (um[c] < 0) {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char prev = st.top();
                st.pop();
                if (um[c] + um[prev] != 0) {
                    return false;
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};

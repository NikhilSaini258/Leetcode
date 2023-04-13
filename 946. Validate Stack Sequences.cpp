class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (auto& e: pushed) {
            s.push(e);
            while (!s.empty() && popped[j] == s.top()) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

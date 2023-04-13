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

// Space Optimized solution
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        for (auto& e: pushed) {
            pushed[i++] = e;
            while (i > 0 && popped[j] == pushed[i-1]) {
                i--;;
                j++;
            }
        }
        return i == 0;
    }
};

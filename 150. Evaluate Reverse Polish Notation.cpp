class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long long> s;
        for (auto& e : tokens) {
            if (e == "+" || e == "-" || e == "*" || e == "/") {
                long long result = 0;
                long long x = s.top();
                s.pop();
                long long y = s.top();
                s.pop();
                if (e == "+") result = y + x;
                else if (e == "-") result = y - x;
                else if (e == "*") result = y * x;
                else if (e == "/") result = y / x;
                s.push(result);
            } else {
                s.push(stoi(e));
            }
        }
        return s.top();
    }
};

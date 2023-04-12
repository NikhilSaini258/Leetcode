// Brute Force
class Solution {
public:
    string removeStars(string str) {
        std::stack<char> s;

        for(auto& c: str) {
            if (c == '*' && !s.empty()) s.pop();
            else s.push(c);
        }
        std::string outStr;
        while (!s.empty()) {
            outStr += s.top();
            s.pop();
        }
        std::reverse(outStr.begin(), outStr.end());
        return outStr;
    }
};

// Optimised Solution
class Solution {
public:
    string removeStars(string str) {
        std::string outStr;
        for(auto& c: str) {
            if (c == '*') outStr.pop_back();
            else outStr.push_back(c);
        }
        return outStr;
    }
};

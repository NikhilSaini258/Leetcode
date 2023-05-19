class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() - 1;
        std::sort (strs.begin(), strs.end());

        int index = 0;
        for (int i = 0; i < strs[0].size() && i < strs[n].size(); i++) {
            if (strs[0][i] != strs[n][i]) break;
            index++;
        }

        return strs[0].substr (0, index);
    }
};

// Another solution without using sorting
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        if (strs.size() == 0) {
            return ans;
        }

        int index = 0;  // Index of each element
        for (auto& c: strs[0]) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].size() <= index || c != strs[i][index]) {
                    return ans;
                }
            }
            index++;
            ans += c;
        }
        return ans;
    }
};

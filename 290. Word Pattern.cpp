class Solution {
public:
    vector<string> splitString(string s) {
        string word;
        vector<string> ans;
        istringstream ss (s);
        while (ss >> word) {
            ans.push_back(word);
        }
        return ans;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> strArr = splitString(s);
        if (strArr.size() != pattern.size()) {
            return false;
        }
        unordered_map<char, string> um;
        set<string> st;

        for (int i = 0; i < pattern.size(); i++) {
            if (um.find(pattern[i]) == um.end() && st.find(strArr[i]) == st.end()) {
                um[pattern[i]] = strArr[i];
                st.insert(strArr[i]);
            } else if (um[pattern[i]] != strArr[i]) {
                return false;
            }
        }
        return true;
    }
};

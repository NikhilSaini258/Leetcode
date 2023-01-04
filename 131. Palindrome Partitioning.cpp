class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string& str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string& s, int i, vector<string>& each) {
        if (i >= s.length()) {
            ans.push_back(each);
        }
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                each.push_back(s.substr(i, j+1-i));
                solve(s, j+1, each);
                each.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> each;
        solve(s, 0, each);
        return ans;
    }
};

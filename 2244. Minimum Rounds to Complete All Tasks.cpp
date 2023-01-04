// Mathematic solution
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;   // {number, count}
        int ans = 0;

        for (auto& e : tasks) mp[e]++;

        for (auto& e : mp) {
            if(e.second == 1) return -1;   // Not possible
            else if (e.second == 2) ans++;
            else {
                ans += (e.second+2)/3;
            }
        }
        return ans;
    }
};

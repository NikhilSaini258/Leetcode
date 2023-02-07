class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int h = 0;
        int ans = 0;
        unordered_map<int, int> um;  // {fruitType, count}
        while (h < fruits.size()) {
            um[fruits[h]]++;
            if (um.size() > 2) {
                if (um[fruits[l]] == 1) {
                    um.erase(fruits[l]);
                } else {
                    um[fruits[l]]--;
                }
                l++;
            }
            ans = std::max(h-l+1, ans);
            h++;
        }
        return ans;
    }
};

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto max = std::max_element(candies.begin(), candies.end());
        vector<bool> b;
        for(auto& c : candies)
        {
            if(c + extraCandies >= *max) b.push_back(true);
            else b.push_back(false);
        }
        return b;
    }
};

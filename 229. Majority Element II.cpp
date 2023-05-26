class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Using Moore's Voting Algorithm
        // Any length of nums, min(ans) can be zero and max(ans) is nums.size()/3 -> At most 2 elements can be majority element

        vector<int> ans;
        int maxMajoritySize = nums.size() / 3;
        int count1 = 0, count2 = 0;
        int element1 = INT_MIN, element2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && nums[i] != element2) {
                count1 = 1;
                element1 = nums[i];
            } else if (count2 == 0 && nums[i] != element1) {
                count2 = 1;
                element2 = nums[i];
            } else if (nums[i] == element1) count1++;
            else if (nums[i] == element2) count2++;
            else {
                count1--;
                count2--;
            }
        }

        // Verifying result
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (element1 == nums[i]) cnt1++;
            if (element2 == nums[i]) cnt2++;
        }

        // Verify whether selected element is occuring more than N/3
        if (cnt1 > maxMajoritySize) ans.push_back (element1);
        if (cnt2 > maxMajoritySize) ans.push_back (element2);
        return ans;
    }
};

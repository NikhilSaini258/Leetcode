class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algo
        int l = 0;
        int m = 0;
        int h = nums.size() - 1;
        while (m <= h) {
            if (nums[m] == 0) {
                std::swap (nums[l], nums[m]);
                l++;
                m++;
            } else if (nums[m] == 1) {
                m++;
            } else if (nums[m] == 2) {
                std::swap (nums[m], nums[h]);
                h--;
            }
        }
    }
};

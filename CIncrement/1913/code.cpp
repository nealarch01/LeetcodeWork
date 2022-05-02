class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int a = nums[nums.size() - 1];
        int b = nums[nums.size() - 2];
        int c = nums[1];
        int d = nums[0];
        return (a * b) - (c * d);
    }
};

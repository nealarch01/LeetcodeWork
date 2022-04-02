class Solution {
public:
    int findPivot(const vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;
        while (left < right) {
            if (nums[middle] >= nums[0]) {
                left = middle + 1;
            } else {
                right = middle;
            }
            middle = (left + right) / 2;
        }
        return left; // left will always be the pivot point
    }
    int binarySearch(const vector<int> &nums, int left, int right, int target) {
        int middle = (left + right) / 2;
        while (left <= right) {
            if (nums[middle] == target) {
                return middle;
            } else if (target < nums[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            middle = (left + right) / 2; // calculate new middle for the next iteration
        }
        return -1; // not found
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        cout << pivot << endl;
        int ar1 = binarySearch(nums, 0, pivot - 1, target);
        if (ar1 == -1) {
            return binarySearch(nums, pivot, nums.size() - 1, target);
        }
        return ar1;
    }
};

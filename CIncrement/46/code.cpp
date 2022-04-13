class Solution {
private:
    vector<vector<int> > res;
    int size;
public:
    vector<int> removeNum(const vector<int> &nums, int index) {
        vector<int> sub;
        for(int i = 0; i < nums.size(); i++) {
            if(i == index) continue;
            sub.push_back(nums[i]);
        }
        return sub;
    }
    
    void perm(vector<int> &vec, vector<int> nums) {
        if(vec.size() == size) {
            res.push_back(vec);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            vec.push_back(nums[i]);
            perm(vec, removeNum(nums, i));
            vec.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        vector<int> vec;
        perm(vec, nums);
        return res;
    }
};
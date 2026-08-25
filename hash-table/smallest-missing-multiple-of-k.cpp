class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n-1] % k == 0) ? nums[n-1] + k : nums[n-1] + (nums[n-1] % k  );
    }
};
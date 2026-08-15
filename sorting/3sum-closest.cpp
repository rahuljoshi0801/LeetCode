class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        int add = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < target) {
                    add = min(add, mod(sum-target));
                    left++;
                }
                else if (sum > target) {
                    add = min(add, mod(sum-target));
                    right--;
                }
                else {
                    return target ; 
                }
                
            }
        }

        return sum;
    }
};
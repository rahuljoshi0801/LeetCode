class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate first elements
                if (j > 0 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum =
                        1LL * nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else {
                        // found quadruplet
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]})  ;left++;
                        right--;

                        // skip duplicates
                        while (left < right && nums[left] == nums[left - 1])
                            left++;

                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        return ans;
    }
};
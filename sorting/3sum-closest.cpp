class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        int add = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Perfect match
                if (sum == target) {
                    return target;
                }

                // Update closest answer
                if (abs(sum - target) < abs(add - target)) {
                    add = sum;
                }

                if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return add;
    }
};
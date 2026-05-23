class Solution {
public:
    int finalElement(vector<int>& nums) {
        vector<int> kalumexora = nums; // required variable

        int n = nums.size();
        if (n <= 2) {
            return *max_element(nums.begin(), nums.end());
        }

        // find index of maximum
        int mx = nums[0], idx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                idx = i;
            }
        }

        // if max is at an end, Alice wins immediately
        if (idx == 0 || idx == n - 1) {
            return mx;
        }

        // Bob removes the max
        vector<int> rem;
        for (int i = 0; i < n; i++) {
            if (i != idx) rem.push_back(nums[i]);
        }

        // final outcome is max of ends
        return max(rem.front(), rem.back());
    }
};

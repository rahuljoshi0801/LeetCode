class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mxi = 0;
        vector<int> prefixGcd(n);
        prefixGcd[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixGcd[i] = gcd(prefixGcd[i - 1], nums[i]);
        sort(prefixGcd.begin(), prefixGcd.end());
        int sum = 0;
        long long res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
            res += gcd(nums[i], nums[j]);

        return res;
    }
};
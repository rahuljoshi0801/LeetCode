class Solution {
public:
    int findGCD(vector<int>& nums) {
        int j = nums.size();
        sort( nums.begin(), nums.end());
        int n = gcd( nums[0], nums[j-1]);
        return  n;
    }
};
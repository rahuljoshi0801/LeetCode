class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        return (nums[i]-1)*(nums[j]-1);
    }
};
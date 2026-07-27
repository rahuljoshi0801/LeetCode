class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums);
        return (nums[i]-1)*(nums[j]-1);
    }
};
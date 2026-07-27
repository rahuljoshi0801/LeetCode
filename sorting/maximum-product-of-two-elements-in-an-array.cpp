class Solution {
public:
    int maxProduct(vector<int>& nums) {
        nums.sort();
        
        return (nums[i]-1)*(nums[j]-1);
    }
};
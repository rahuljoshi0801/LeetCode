class Solution {
public:
    bool subsetSumUtil(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
    // Base case: If the target sum is 0, we found a valid partition
    if (target == 0)
        return true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return nums[0] == target;

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    // 1. Exclude the current element
    bool notTaken = subsetSumUtil(ind - 1, target, nums, dp);

    // 2. Include the current element if it doesn't exceed the target
    bool taken = false;
    if (nums[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - nums[ind], nums, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken || taken;
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for( int i =0 ; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false ;
        else {
            int k = sum /2;
            vector<vector<int>> dp(n, vector<int>(k+1,-1));
            return subsetSumUtil(n - 1, k, nums, dp);
        }
    }

};
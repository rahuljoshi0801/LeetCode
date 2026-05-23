class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // value -> index
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];

            // check if complement already seen
            if(mp.count(complement)) {
                return {i, mp[complement]}; 
            }

            // store current number with index
            mp[nums[i]] = i;
        }

        return {}; // in case no solution found
    }
};

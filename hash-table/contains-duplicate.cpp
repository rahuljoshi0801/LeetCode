class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp; 
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                return true;  // duplicate found
            }
            mp[nums[i]]++;  // insert/update map
        }
        return false;  // no duplicates
    }
};

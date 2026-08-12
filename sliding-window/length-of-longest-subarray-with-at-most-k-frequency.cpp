class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int ,int > freq ;
        int res = 0 ;
        int n = nums.size();
        int i = 0, j = 0 ;
        while( j <n){
            freq[nums[j]]++;
            while (freq[nums[j]]>k) {
                freq[i]--;
                i++;
            }
            res = max ( res , j-i+1);
            j++;
        }
        return res ;
    }
};
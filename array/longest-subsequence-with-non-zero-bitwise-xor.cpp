class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int x;
        std::unordered_set<int> my_set(nums.begin(), nums.end());
        for (const auto& element : my_set) {
        x = element^x;
    }
    size_t = my_set.size();
    if (x != 0) return t;
    else return t-1;
    }
};
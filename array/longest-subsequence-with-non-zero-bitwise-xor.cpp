class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int x;
        std::unordered_set<int> my_set(nums.begin(), nums.end());
        for (const auto& element : my_set) {
        x = element^x;
    }
    if (x != 0) return my_set.size();
    else return my_set.size()-1;
    }
};
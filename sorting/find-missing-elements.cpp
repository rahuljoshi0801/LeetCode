class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> ans;

        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());

        for (int i = a; i <= b; i++) {
            if (!s.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
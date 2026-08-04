class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int j = 0;
        vector<int> ans;
        int a = nums[0];
        int b = nums[n-1];
        for (int i = a; i <= b; i++) {
            for(int k =0; k<=b; k++)
            {if (i == nums[k]) {
                continue;
            }
            ans.push_back(i);
            j++;}
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        sort( nums.begin(), nums.end());
        int j =0;
        vector<int> ans;
        for( int i = nums[0]; i<= nums[n-1]; i++){
            if(i==nums[i]){
                continue;
            }
            ans[j] = nums[i];
            j++;
        }
        return ans;
    }
};
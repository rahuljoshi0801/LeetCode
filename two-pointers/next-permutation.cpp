class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for( int i = n-2; i < n; i--){
            if(nums[i]>nums[i+1]){
            ind = i;
            break ;
            }
        }
        if( ind = -1){
            reverse(nums.begin(), nums.end());
        }
        for(int i = index; i< n ;i++){
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
        return 

    }
};
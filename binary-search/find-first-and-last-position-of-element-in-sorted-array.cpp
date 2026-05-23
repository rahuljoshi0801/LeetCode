class Solution {
public:
    int f(vector<int>& nums, int target){
        int l =0,h = nums.size()-1, ans=-1 ;
        while( l<=h){
             int mid = l+ (h-l)/2;
            if (nums[mid]==target){
                ans = mid ;
                h = mid-1;
            }
            else if (nums[mid]<target){
                l = mid +1;
            }
            else {
                h = mid-1;
            }

        } 
        return ans;
    }
    int l(vector<int>& nums, int target){
        int l =0,h = nums.size()-1, ans=-1 ;
        while( l<=h){
             int mid = l+ (h-l)/2;
            if (nums[mid]==target){
                ans = mid ;
                l= mid+1;
            }
            else if (nums[mid]<target){
                l = mid +1;
            }
            else {
                h = mid-1;
            }

        } 
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {f(nums, target), l (nums,target)};
    }
};
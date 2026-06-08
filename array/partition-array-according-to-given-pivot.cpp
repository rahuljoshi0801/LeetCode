class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        int j =0;
        int n = nums.size();
        for(int i =0 ; i<n; i++){
            if(nums[i]<pivot) v[j++] = nums[i];
        }
        for(int i =0 ; i<n; i++){
            if(nums[i]==pivot) v[j++] = nums[i];
        }
        for(int i =0 ; i<n; i++){
            if(nums[i]>pivot) v[j++] = nums[i];
            
        }
        return v;
    }
};
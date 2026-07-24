class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int > set ;
        for( int i =0 ; i< n; i++){
            
            for(int j =i ;j<n;j++){
                
                for( int k =j ; k<n ;k ++ ){
                    set.insert(nums[i]^nums[j]^nums[k]);
                }
            }
        }
        return set.size();
    }
};
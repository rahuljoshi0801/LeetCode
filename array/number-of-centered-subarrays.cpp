class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int  n= nums.size();
        int count  =0 ; 

        for (int i =0 ;i < n; i++ ){
        unordered_set<long long  >seen ;
        long long sum = 0 ;
            for (int  r = i ;r <n ; r++ ){
                sum+= nums [r]; 
                seen.insert(nums[r]);
                if ( seen.count(sum)) count ++;

            }

           
        } return count ; 
            
    }
};
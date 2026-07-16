class Solution {
public:
    
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mxi = 0;
        vector<int> prefixGcd(n);
        for( int i=0; i < n;i++){
            mxi = max(mxi , nums[i]);
            prefixGcd[i] = gcd(nums[i], mxi);
        }
        sort( prefixGcd.begin(), prefixGcd.end());
        int sum = 0;
        long long res = 0;
        for (int i = 0, j = A.size() - 1; i < j; i++, j--)
            res += gcd(A[i], A[j]);

        return res;
    }
};
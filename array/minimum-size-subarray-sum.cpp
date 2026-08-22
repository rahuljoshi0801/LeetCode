class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //int i =0 ;j =i+1;
        int n= nums.size();
        int count = INT_MAX;
        for(int i =0 ; i<n;i++){
            for( int j = i+1;j<n; j++ ){
                if( nums[ i] + nums[j] => target){
                    count = min( count , j -i+1 );
                    i++ ;
                    
                }else if ( nums[ i] + nums[j] <target){
                    j++;
                }
            }
        }
        return count == INT_MAX ? 0 : count ;

    }
};
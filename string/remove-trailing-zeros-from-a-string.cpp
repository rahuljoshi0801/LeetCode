class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.length(); 
        int temp ;
        for( int i = n-1; i >=0; i--){
            if( num[i] != '0') {
                temp = i;
                break ; }

        }
        string ans = num.substr(0, temp + 1); 
        return ans;

    }
};
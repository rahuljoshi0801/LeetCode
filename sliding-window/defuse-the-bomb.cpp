class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n , 0);
        int sum =0 , ein , eout;
        if ( k ==0 )   return res ;
        else if ( k > 0){
            
            for ( int i =1 ; i <= k ; i++ ){
                sum += code[i%n];
            }
            for( int i = 0 ;i<n; i++){
                res[i] = sum;
                eout = (i + 1)%n;
                ein = (i + k+ 1)%n;
                sum =( sum - code[eout]) + code[ein] ;
            }

        }else {
            k = abs(k);
            for( int i = n-k ; i<n;i++){
                sum +=code[i];
            }
            for(int i =0 ;i <n ;i++){
                res[i] = sum ;
                eout = ( i + n- k)% n;
                ein = i;
                sum = (sum - code[eout]) + code[ein];
            }
        }
        return res;

    }
};
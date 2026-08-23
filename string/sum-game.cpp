class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int lks =0 , rks = 0;
        int lq = 0, rq =0;
        
        for ( int i =0 ; i<n/2; i++){
            if ( num[i] == '?' ){
                lq ++;
            }else lks +=num[i] - '0';
        }
        for( int i = n/2  ; i<n ;i++){
            if ( num[i] == '?' ){
                rq ++;
            }else rks += (int)num[i] - '0';
        }
        cout << rq <<endl << lq<<endl;
        cout << lks << endl<< rks<<endl;
        cout << (2*rks + 9*rq)<<endl;
        cout << (2*lks + 9*lq);
        if ( (2*lks + 9*lq) == (2*rks + 9*rq) ) return false;
        else return true;

        
    }
};
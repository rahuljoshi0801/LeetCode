class Solution {
public:
    int countMonobit(int n) {
        int count =1 ; 

        for (int k = 1; ; k++) {
            int val = (1 << k) - 1;
            if (val > n) break;
            count++;
        }
        return count;
    }
};
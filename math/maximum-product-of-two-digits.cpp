class Solution {
public:
    int maxProduct(int n) {
        vector<int> a;

        while (n > 0) {
            a.push_back(n % 10);
            n /= 10;
        }

        sort(a.begin(), a.end());

        int m = a.size();
        return a[m - 1] * a[m - 2];
    }
};
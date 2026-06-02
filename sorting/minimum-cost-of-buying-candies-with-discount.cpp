class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int sum = 0;

        sort(cost.begin(), cost.end());

        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt++;
            if (cnt % 3 == 0) continue; // every 3rd candy is free
            sum += cost[i];
        }

        return sum;
    }
};
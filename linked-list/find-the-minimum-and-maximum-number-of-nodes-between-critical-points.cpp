class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> a;

        // Convert linked list to array
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }

        vector<int> critical;

        // Find critical points
        for (int i = 1; i < a.size() - 1; i++) {
            if ((a[i] > a[i - 1] && a[i] > a[i + 1]) ||
                (a[i] < a[i - 1] && a[i] < a[i + 1])) {
                critical.push_back(i);
            }
        }

        // Fewer than 2 critical points
        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;

        // Minimum distance between consecutive critical points
        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i - 1]);
        }

        // Maximum distance = last - first
        int maxDist = critical.back() - critical.front();

        return {minDist, maxDist};
    }
};
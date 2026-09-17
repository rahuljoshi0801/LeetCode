class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int i = 0;
        int j = 0;

        int currSum = 0;

        vector<int> minBestLenTillIdx(n, INT_MAX);

        int bestMinLen = INT_MAX;
        int result = INT_MAX;

        while (j < n) {

            currSum += arr[j];

            // Shrink window if sum becomes too large
            while (i <= j && currSum > target) {
                currSum -= arr[i];
                i++;
            }

            // Found a subarray [i...j]
            if (currSum == target) {

                int len = j - i + 1;

                // Need a previous non-overlapping subarray
                if (i > 0 && minBestLenTillIdx[i - 1] != INT_MAX) {
                    result = min(
                        result,
                        len + minBestLenTillIdx[i - 1]
                    );
                }

                // Best subarray found so far
                bestMinLen = min(bestMinLen, len);
            }

            minBestLenTillIdx[j] = bestMinLen;

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};
/*
    Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum 
    sum and return them.
    Return the result as a list of indices representing the starting position of each interval (0-indexed). 
    If there are multiple answers, return the lexicographically smallest one.
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subarraySum(n - k + 1, 0);
        vector<int> left(n, 0), right(n, 0);

        for (int i = 0; i < k; i++) {
            subarraySum[0] += nums[i];
        }
        for (int i = 1; i <= n - k; i++) {
            subarraySum[i] = subarraySum[i - 1] - nums[i - 1] + nums[i + k - 1];
        }

        int best = 0;
        for (int i = 0; i <= n - k; i++) {
            if (subarraySum[i] > subarraySum[best]) {
                best = i;
            }
            left[i] = best;
        }

        best = n - k;
        for (int i = n - k; i >= 0; i--) {
            if (subarraySum[i] >= subarraySum[best]) {
                best = i;
            }
            right[i] = best;
        }

        vector<int> result = {-1, -1, -1};

        int maxSum = 0;

        for (int mid = k; mid <= n - 2 * k; mid++) {
            int l = left[mid - k];
            int r = right[mid + k];
            int total = subarraySum[l] + subarraySum[mid] + subarraySum[r];
            if (total > maxSum) {
                maxSum = total;
                result = {l, mid, r};
            }
        }

        return result;
    }
};
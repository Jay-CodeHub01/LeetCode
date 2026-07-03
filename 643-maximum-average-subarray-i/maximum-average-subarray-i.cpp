class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        // Initial window sum
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxSum = sum;

        // Slide the window
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};
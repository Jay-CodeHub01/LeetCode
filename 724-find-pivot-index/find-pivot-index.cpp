class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Calculate the total sum of all elements in the array
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Right sum is totalSum minus leftSum minus the current element
            int rightSum = totalSum - leftSum - nums[i];

            // If the sums on both sides match, we found the pivot index
            if (leftSum == rightSum) {
                return i;
            }

            // Update the running left sum for the next iteration
            leftSum += nums[i];
        }

        // Return -1 if no pivot index exists
        return -1;
    }
};
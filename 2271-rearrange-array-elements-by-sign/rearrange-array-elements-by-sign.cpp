class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        // Create a result array of size n initialized with 0
        vector<int> ans(n, 0);

        // posIndex will store index for next positive number (even index)
        // negIndex will store index for next negative number (odd index)
        int posIndex = 0, negIndex = 1;

        // Loop through the original array
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                // Place negative numbers at odd indices
                ans[negIndex] = nums[i];
                negIndex += 2;
            } else {
                // Place positive numbers at even indices
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};
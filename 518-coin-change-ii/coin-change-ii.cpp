class Solution {
public:
    int find(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 1;          // valid combination
        if (index < 0) return 0;            // no coins left

        if (dp[index][amount] != -1) return dp[index][amount];

        // Option 1: skip current coin
        int notTake = find(index - 1, amount, coins, dp);

        // Option 2: take current coin (if possible)
        int take = 0;
        if (coins[index] <= amount) {
            take = find(index, amount - coins[index], coins, dp);
        }

        return dp[index][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return find(n - 1, amount, coins, dp);
    }
};
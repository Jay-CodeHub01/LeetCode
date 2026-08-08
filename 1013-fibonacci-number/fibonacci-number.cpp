class Solution {
public:
    // int find(int n, vector<int>&dp){
    //     if(n<=1){
    //         return n;
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     return find(n-1, dp)+find(n-2, dp);
    // }
    // int fib(int n) {
    //     vector<int>dp(n+1,-1);
    //     return find(n, dp);
    // }

    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i<=n ; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
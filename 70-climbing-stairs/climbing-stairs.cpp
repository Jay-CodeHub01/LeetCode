class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        // vector<int>dp(n+1,-1);
        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 2;

        // for(int i=3; i<=n ; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }

        // return dp[n];

        int first = 1;
        int second = 2;
        int third;
        for(int i = 3;i<=n; i++){
            third = first+second;
            first = second;
            second = third;
        }

        return third;
    }
};
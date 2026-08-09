class Solution {
public:
    // int find(int index, int n, vector<int>&nums, vector<int>&dp){
    //     if(index >= n) return 0;
    //     if(dp[index] != -1) return dp[index];

    //     return max(nums[index] + find(index+2, n, nums, dp) , find(index+1, n ,nums, dp));
    // }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+2,-1);
        vector<int>dp2(n+2,-1);

        dp1[n-1] = dp1[n] = dp2[n] = dp2[n+1] = 0;

        for(int i=n-2 ; i>=0 ; i--){
            dp1[i] = max(nums[i] + dp1[i+2] , dp1[i+1]);
        }

        for(int i=n-1 ; i>0 ; i--){
            dp2[i] = max(nums[i] + dp2[i+2] , dp2[i+1]);
        }
        
        // return max(find(0,n-1,nums,dp1) , find(1,n,nums,dp2));
        return max(dp1[0] , dp2[1]);
    }
};
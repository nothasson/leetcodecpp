class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int>dp(len);
        dp[0] = nums[0];
        for(int i = 1; i < len ; i++){
            if(dp[i - 1] >= 0){
                dp[i] = dp[i - 1] + nums[i];
            }else{
                dp[i] = nums[i];
            }
        }
        int res = dp[0];
        for(int i = 1; i < len ; i++){
            res = max(res,dp[i]);
        }
        return res;
    }
};
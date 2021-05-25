class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int>dp(len);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < len ; i++){
            if(dp[i - 1] >= 0){
                dp[i] = dp[i - 1] + nums[i];
            }else{
                dp[i] = nums[i];
            }
            res = max(res,dp[i]);
        }
        return res;
    }
    int maxSubArray(vector<int>& nums) { //状态压缩
        int len = nums.size();
        int sum = 0;
        int res = nums[0];
        for(int i = 0; i < len ; i++){
            if(sum >= 0){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            res = max(res,sum);
        }
        return res;
    }
};
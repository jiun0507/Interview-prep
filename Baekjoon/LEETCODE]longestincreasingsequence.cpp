class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int dp[len];
        for(int i = 0;i<len;i++) dp[i] = 1;
        for(int i = 0;i<len;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int ret = 0;
        for(int i = 0;i<len;i++){
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int dp[nums.size()][m];
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<nums.size();i++){
            dp[i][0] = nums[i];
            if(i>0) dp[i][0] += dp[i-1][0];
        }
        for(int i = 1;i<m;i++){
            for(int j = i-1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    if(dp[k][i] == -1 || dp[k][i] > max(dp[k][0] - dp[j][0], dp[j][i-1])){
                        dp[k][i] = max(dp[k][0] - dp[j][0], dp[j][i-1]);
                    }
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<dp[j][i]<<" ";
            }
        }
        return dp[n-1][m-1];
    }
};
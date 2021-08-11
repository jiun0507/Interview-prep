class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_min[n];
        int dp_max[n];
        for(int i = 0;i<n;i++){
            dp_min[i] = prices[i];
            if(i>0){
                dp_min[i] = min(dp_min[i], dp_min[i-1]);
            }
        }
        for(int i = n-1;i>=0;i--){
            dp_max[i] = prices[i];
            if(i<n-1){
                dp_max[i] = max(dp_max[i], dp_max[i+1]);
            }
        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            if(ans < dp_max[i+1] - dp_min[i]){
                ans = dp_max[i+1] - dp_min[i];
            }
        }
        return ans;
    }
};
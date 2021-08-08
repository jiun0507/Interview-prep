class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        int min = 1000000001;
        int ret = nums[0];
        for(int i = 0;i<n;i++){
            if(ret<nums[i]) ret = nums[i];
        }
        for(int i = 0;i<n;i++){
            sum += nums[i];
            
            if(ret < sum) ret = sum;
            if(i>0 && ret<sum-min) ret = sum-min;
            if(min>sum) min=sum;
        }
        
        return ret;
    }
};
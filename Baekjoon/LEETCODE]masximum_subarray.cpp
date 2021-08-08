class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> partial_sum(nums.size(), 0);
        int min = 1000000001;
        int ret = nums[0];
        for(int i = 0;i<n;i++){
            if(ret<nums[i]) ret = nums[i];
        }
        for(int i = 0;i<n;i++){
            partial_sum[i] = nums[i];
            if(i>0) partial_sum[i] += partial_sum[i-1];
            
            if(ret < partial_sum[i]) ret = partial_sum[i];
            if(i>0 && min!=1000000001 && ret<partial_sum[i]-min) ret = partial_sum[i]-min;
            if(min>partial_sum[i]) min=partial_sum[i];
        }
        
        return ret;
    }
};
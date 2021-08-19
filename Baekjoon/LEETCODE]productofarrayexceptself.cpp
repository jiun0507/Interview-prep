class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = nums;
        vector<int> suffix = nums;
        for(int i = 0;i<n;i++){
            if(i>0) prefix[i] *= prefix[i-1];
            if(n-1-i<n-1) suffix[n-1-i] *= suffix[n-i];
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            bool zero = true;
            int temp = 0;
            if(i>0){
                temp = prefix[i-1];
                zero = false;
            }
            if(i<n-1){
                if(!zero) temp *= suffix[i+1];
                else{
                    temp = suffix[i+1];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = nums[0];
        vector<int> ans(n, 0);
        ans[0] = ans[n-1] = 1;
        for(int i = 1;i<n;i++){
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = nums[n-1];
        for(int i = n-2;i>=0;i--){
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        
        return ans;
    }
};
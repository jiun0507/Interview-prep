class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret= 10001;
        int diff = 10001;
        cout<<"\n";
        for(int i = 0;i<nums.size()-2;i++){
            for(int j = i+1;j<nums.size()-1;j++){
                
                auto it = lower_bound(nums.begin()+j+1, nums.end(), target-nums[i]-nums[j]);
                if (it == nums.end()) {
                    if(diff > abs(target - nums[i]-nums[j]-nums.back())){
                        diff = abs(target - nums[i]-nums[j]-nums.back());
                        ret = nums[i]+nums[j] + nums.back();
                    }
                }
                else {
                    int k = it - nums.begin();
                    if(diff > abs(target - nums[i]-nums[j]-nums[k])){
                        diff = abs(target - nums[i]-nums[j]-nums[k]);
                        ret = nums[i]+nums[j]+nums[k];
                        if(ret==target) return ret;
                    }
                    if(k-1>j){
                        k--;
                        if(diff > abs(target - nums[i]-nums[j]-nums[k])){
                            diff = abs(target - nums[i]-nums[j]-nums[k]);
                            ret = nums[i]+nums[j]+nums[k];
                            if(ret==target) return ret;
                        }
                    }
                }
            }
        }    
        return ret;
    }
};
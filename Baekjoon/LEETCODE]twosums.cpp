class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> val_to_index;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(val_to_index.count(nums[i])!=0){
                ans.push_back(val_to_index[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            val_to_index[target - nums[i]] = i;
        }
        return ans;
    }
};
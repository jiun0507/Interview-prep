// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        
        for(int i = 0;i<length-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<length-1;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int sum = nums[i] + nums[j];
                if(sum > 0) break;
                if(binary_search(nums.begin()+j+1, nums.end(), sum*(-1))){
                    ans.push_back({nums[i], nums[j], -sum});  
                }

            }
        }
        return ans;
    }
};
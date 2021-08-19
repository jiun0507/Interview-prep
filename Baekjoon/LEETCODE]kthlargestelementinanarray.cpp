class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mini;
        for(int i = 0;i<nums.size();i++){
            mini.push(nums[i]);
            if(mini.size()>k){
                mini.pop();
            }
        }
        return mini.top();
    }
};
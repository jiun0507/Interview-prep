class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one = nums[0];
        bool sec = false;
        int second;
        for(int i = 1;i<nums.size();i++){
            if(sec && second < nums[i]){
                return true;
            }else{
                if(one< nums[i]){
                    sec = true;
                    second = nums[i];
                }
                else if(one >nums[i]){
                    if(one>nums[i]) one = nums[i];
                }   
            }
        }
        return false;
    }
};
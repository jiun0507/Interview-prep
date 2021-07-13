class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        int middle = -1;
        if(begin==end){
            if(nums[begin]==target) return begin;
            else{
                return -1;
            }
        }
        while(nums[begin]>nums[end]){
            middle = (begin+end)/2;
            if(middle>0 && nums[middle-1]>nums[middle]){
                break;
            }
            else if(middle<nums.size()-1 && nums[middle+1]<nums[middle]){
                middle++;
                break;
            }
            if(nums[middle]>nums[begin]){
                begin =middle;
            }
            else{
                end = middle;
            }
        }
        if(middle==-1){
            auto it = find(nums.begin(), nums.end(), target);
            if (it == nums.end()) {
                return -1;
            }
            else {
                return it - nums.begin();
            }
        }
        if(target < nums[0]){
            auto it = find(nums.begin()+middle, nums.end(), target);
            if (it == nums.end()) {
                return -1;
            }
            else {
                return it - nums.begin();
            }
        }
        else if(target > nums[0]){
            auto it = find(nums.begin(), nums.begin()+middle, target);
            if (it == nums.begin()+middle) {
                return -1;
            }
            else {
                return it - nums.begin();
            }
        }
        else if(target == nums[0]){
            return 0;
        }
        return -1;
    }
        
};
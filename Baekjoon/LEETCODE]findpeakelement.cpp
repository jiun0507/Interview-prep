class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int cur = len/2;
        int begin = -1;
        int end = len;
        do{
            cur = (begin + end)/2;
            if((cur==0 || nums[cur] > nums[cur-1])&&(cur==len-1 ||nums[cur]>nums[cur+1])){
                return cur;
            } else{
                if(cur>0 && nums[cur-1]>nums[cur]){
                    end = cur;
                } else if(cur<len-1 && nums[cur+1] >nums[cur]){
                    begin = cur;
                } else{
                    break;
                }
            }
        }while(begin<end);
        return 0;
    }
};
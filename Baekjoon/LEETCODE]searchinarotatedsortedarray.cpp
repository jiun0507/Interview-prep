class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return nums[0] == target ? 0: -1;
        int k = n;
        int start =0;
        int end = n-1;
        if(nums[start]>nums[end]){
            while(start<=end){
                int middle = (start + end) / 2;
                cout<<start<<" "<<end<<" "<<middle<<":"<<nums[middle]<<"\n";
                if(middle>0 && nums[middle]<nums[middle-1]){
                    k = middle; break;
                }
                if(nums[middle] >= nums[0]){
                    start = middle + 1;
                } else{
                    end = middle;
                }
            }  
        }

        cout<<k<<"\n";
        if(target >= nums[0]){
            auto it = find(nums.begin(), nums.begin() + k, target);
            if(it == nums.begin()+k || *it != target) return -1;
            return it - nums.begin() ;
        } else{
            auto it = find(nums.begin() + k, nums.end(), target);
            if(it == nums.end() || *it != target) return -1;
            return it - nums.begin() ;
        }
        
        return 0;
        
    }
};
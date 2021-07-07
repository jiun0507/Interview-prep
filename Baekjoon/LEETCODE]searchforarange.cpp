class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end()) {
            return vector<int>(2, -1);
        }
        else {
            vector<int> ret(2, it - nums.begin());
            it++;
            while(it!=nums.end() && *it==target){
                ret[1]++;
                it++;
            }
            return ret;
        }
    }
};
class Solution {
public:
    bool get(int bitmask, int index){
        return bitmask & (1<<index);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = nums.size();
        for(int i = 0; i<(1<<len);i++){
            vector<int> cur;
            for(int j=0;j<len;j++){
                if(get(i, j)) cur.push_back(nums[j]);
            }
            ret.push_back(cur);
        }
        return ret;
    }
};
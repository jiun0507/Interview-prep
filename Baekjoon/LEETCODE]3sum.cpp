class Solution {
public:
    void remove(std::vector<int> &v)
    {
        auto end = v.end();
        for (auto it = v.begin(); it != end; ++it) {
            end = std::remove(it + 1, end, *it);
        }

        v.erase(end, v.end());
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3) return ret;
        map<pair<int,int>, int> indexes;
        sort(nums.begin(), nums.end());

        for(int i = 0;i<nums.size()-2;i++){
            for(int j = i+1;j<nums.size()-1;j++){
                if(nums[i]+nums[j]+nums[j+1]>0){
                    break;
                }
                if(nums[i]+nums[j] + nums.back()<0){
                    continue;
                }
                if(indexes.count(make_pair(nums[i], nums[j]))!=0) continue;

                auto it = find(nums.begin()+j+1, nums.end(), (-1)*(nums[i]+nums[j]));
                if (it == nums.end()) {
                    continue;
                }
                else {
                    int k = it - nums.begin();
                    ret.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    indexes[make_pair(nums[i], nums[j])] = 1;
                }
            }
        }        
        return ret;
    }
};
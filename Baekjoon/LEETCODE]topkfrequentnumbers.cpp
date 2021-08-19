class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        for(int i= 0;i<nums.size();i++){
            if(m.count(nums[i])==0){
                m[nums[i]] = 1;
            } else{
                m[nums[i]]++;
            }
        }
        map<int, int>::iterator it;
        vector<pair<int,int>> freq;
        for(it = m.begin();it!=m.end();it++){
            cout<<it->first<<" "<<it->second<<"\n";
            freq.push_back(make_pair(it->second, it->first));
        }
        sort(freq.begin(), freq.end());
        vector<int> ans;
        for(int i = freq.size();i > freq.size()-k; i--){
            ans.push_back(freq[i-1].second);
        }
        return ans;
    }
};
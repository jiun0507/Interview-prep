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
        struct myCompare{
           bool operator()(const pair<int, int>& A, const pair<int, int>& B) {
               return A.first < B.first;
           }  
        };
        vector<pair<int,int>> freq;
        for(it = m.begin();it!=m.end();it++){
            cout<<it->first<<" "<<it->second<<"\n";
            freq.push_back(make_pair(it->second, it->first));
        }
        sort(freq.begin(), freq.end(), myCompare());
        vector<int> ans;
        for(int i = freq.size();i > freq.size()-k; i--){
            ans.push_back(freq[i-1].second);
        }
        return ans;
    }
};

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
        struct myCompare{
           bool operator()(const pair<int, int>& A, const pair<int, int>& B) {
               return A.first > B.first;
           }  
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, myCompare> freq;
        for(it = m.begin();it!=m.end();it++){
            freq.push(make_pair(it->second, it->first));
            if(freq.size()>k) freq.pop();
        }
        vector<int> ans;
        for(int i = 0;i < k; i++){
            ans.push_back(freq.top().second);
            freq.pop();
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<vector<int>, int> indexes;
        int index = 0;
        for(auto &str: strs){
            vector<int> alp(26, 0);
            for(auto &ch:str){
                alp[ch-'a']++;
            }
            if(indexes.count(alp)==0){
                indexes[alp] = index;
                index++;
                ret.push_back(vector<string>(1, str));
            } else{
                ret[indexes[alp]].push_back(str);
            }
        }
        return ret;
    }
    
};
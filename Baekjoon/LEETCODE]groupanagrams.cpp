class Solution {
public:
    vector<int> returnAlphabets(string &str){
        vector<int> ret(26, 0);
        for(auto &a: str){
            ret[a-'a']++;
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagrams;
        vector<vector<int>> alphabetList;
        for(auto &str: strs){
            vector<int> alphabets = returnAlphabets(str);
            if(anagrams.count(alphabets) == 0){
                anagrams[alphabets] = vector<string>(1, str);
                alphabetList.push_back(alphabets);
            } else{
                anagrams[alphabets].push_back(str);
            }
        }
        vector<vector<string>> ans;
        for(auto alphabet: alphabetList){
            ans.push_back(anagrams[alphabet]);
        }
        
        return ans;
    }
};
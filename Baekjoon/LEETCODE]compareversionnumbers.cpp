class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos = 0;
        string token;
        vector<string> v1;
        while ((pos = version1.find(".")) != string::npos) {
            token = version1.substr(0, pos);
            v1.push_back(token);
            version1.erase(0, pos + 1);
        }
        v1.push_back(version1);
        vector<string> v2;
        while ((pos = version2.find(".")) != string::npos) {
            token = version2.substr(0, pos);
            v2.push_back(token);
            version2.erase(0, pos + 1);
        }
        v2.push_back(version2);
        for(int i = 0;i<v1.size();i++){
            int trailingZeroes = 0;
            while(v1[i][trailingZeroes] == '0'){
                trailingZeroes++;
                if(v1[i].size()==trailingZeroes) break;
            }
            v1[i] = v1[i].substr(trailingZeroes);
        }
        for(int i = 0;i<v2.size();i++){
            int trailingZeroes = 0;
            while(v2[i][trailingZeroes] == '0'){
                trailingZeroes++;
                if(v2[i].size()==trailingZeroes) break;
            }
            v2[i] = v2[i].substr(trailingZeroes);
        }
        int maxLength = max(v1.size(), v2.size());
        for(int i = 0;i<maxLength;i++){
            int first = 0;
            int second = 0;
            if(v1.size()>i){
                if(v1[i] != "") first = stoi(v1[i]);
            } 
            if(v2.size()>i){
                if(v2[i] != "") second = stoi(v2[i]);
            }
            if(first > second) return 1;
            else if(first < second) return -1;
        }
        return 0;
    }
};
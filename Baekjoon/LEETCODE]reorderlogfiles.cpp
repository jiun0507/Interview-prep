class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        struct comp{
            bool operator()(pair<string,string>& a, pair<string,string>& b){
                if(a.second.compare(b.second) == 0){
                    return a.first.compare(b.first) < 0;
                }
                return a.second.compare(b.second) < 0;
            }  
        };
        vector<pair<string, string>> letter_logs;
        vector<string> digit_logs;
        string identifier, token;
        for(int i = 0;i<logs.size();i++){
            int pos = logs[i].find(" ");
            if(pos!=logs[i].size()){
                identifier = logs[i].substr(0, pos);
                token = logs[i].substr(pos+1);
                if(token[0] - '0' <=9 && '9'- token[0]<=9){
                    digit_logs.push_back(logs[i]);
                } else{
                    letter_logs.push_back(make_pair(identifier, token));
                }
            }
        }
        sort(letter_logs.begin(), letter_logs.end(), comp());
        vector<string> ans;
        for(auto& letters: letter_logs){
            ans.push_back(letters.first + " " + letters.second);
        }
        for(auto& digits: digit_logs){
            ans.push_back(digits);
        }
        return ans;
    }
};
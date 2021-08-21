class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string delims(" !?',;.");
        // Get string split results
        vector<string> words;
        words.push_back(paragraph);
        for(auto& a: delims){
            vector<string> temp;
            int pos = 0;
            for(auto& word: words){
                while((pos = word.find(a)) != string::npos){
                    string token = word.substr(0, pos);
                    temp.push_back(token);
                    word.erase(0, pos + 1);
                }
                if(word!="") temp.push_back(word);
            }
            words = temp;
        }
        for(auto& data:words){
            for_each(data.begin(), data.end(), [](char & c){
                c = ::tolower(c);
            });
        }
        unordered_map<string, int> wordCount;
        for(auto& ban:banned){
            wordCount[ban] = -1;
        }
        int maximum = 0;
        string ans;
        for(auto& word: words){
            if((wordCount.count(word)!=0 &&wordCount[word]!=-1)||wordCount.count(word)==0){
                if(wordCount.count(word)==0) wordCount[word] = 1;
                else{
                    wordCount[word]++;
                }
                if(wordCount[word]>maximum){
                    maximum = wordCount[word];
                    ans = word;
                }
            }
        }
        return ans;
    }
};
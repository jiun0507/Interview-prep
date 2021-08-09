class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alphabets(26, 0);
        for(int i = 0;i<s.size();i++){
            if(alphabets[s[i]-'a']==0){
                alphabets[s[i]-'a']= i+1;
            }
            else if(alphabets[s[i]-'a'] >0){
                alphabets[s[i]-'a'] = -1;
            } 
        }
        int min = 100001;
        for(int i =0;i<26;i++){
            if(alphabets[i]>0){
                if(min > alphabets[i]) min = alphabets[i];
            }
        }
        if(min==100001) return -1;
        return min-1;
        
    }
};
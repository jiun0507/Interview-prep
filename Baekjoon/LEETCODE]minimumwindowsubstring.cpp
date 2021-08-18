class Solution {
public:
    int compare_vectors(vector<int> &s_vector, vector<int>& t_vector){
        bool more = false;
        for(int i = 0;i<52;i++){
            if(s_vector[i] < t_vector[i]){
                return 0;
            } 
            if(s_vector[i] > t_vector[i]){
                more = true;
            }
        }
        if(more) return 2;
        return 1;
    }
    string minWindow(string s, string t) {
        int minLength = 100001;
        string ans = "";
        vector<int> targetAlphabet(52, 0);
        for(auto &c: t){
            if(c >='a'){
                targetAlphabet[c - 'a']++;
            } else{
                targetAlphabet[c-'A' + 26]++;
            }
        }
        int start = 0;
        int end = 0;
        vector<int> alphabets(52, 0);
        if(s[0] >='a'){
            if(targetAlphabet[s[0]-'a']>0) alphabets[s[0]-'a']++;
        } else{
            if(targetAlphabet[s[0]-'A' + 26]>0) alphabets[s[0]-'A' + 26]++;
        }
        while(start <= end){
            int compared = compare_vectors(alphabets, targetAlphabet);
            if(compared!=0){
                if((end - start + 1) < minLength){
                    minLength = end - start + 1;
                    ans = s.substr(start, end - start + 1);
                }
                if(s[start] >='a'){
                    cout<<s[start]<<" ";
                    if(targetAlphabet[s[start]-'a']>0) alphabets[s[start]-'a']--;
                } else{
                    cout<<s[start]<<" ";
                    if(targetAlphabet[s[start]-'A' + 26]>0) alphabets[s[start]-'A' + 26]--;
                }
                start++;
            } else{
                end++;
                if(end == s.size()){
                    break;
                }
                if(s[end] >='a'){
                    if(targetAlphabet[s[end]-'a']>0){
                        alphabets[s[end]-'a']++;
                    }
                } else{
                    if(targetAlphabet[s[end]-'A' + 26]>0) alphabets[s[end]-'A' + 26]++;
                }
            }
        }
        return ans;
    }
};
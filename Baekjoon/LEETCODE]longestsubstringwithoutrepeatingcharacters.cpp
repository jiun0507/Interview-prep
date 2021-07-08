class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0;
        int end = 0;
        int len = s.size();
        if(len==0) return 0;
        map<char, int> alp;
        alp[s[0]] = 1;
        int ret = 1;
        while(end < len){
            if(end==len-1) break;
            char next = s[end+1];
            if(alp[next]!=0){
                alp[s[begin]] = 0;
                begin++;
            } else{
                end++;
                alp[next] = 1;
                ret = max(ret, end - begin + 1);
            }
        }
        return ret;
    }
};
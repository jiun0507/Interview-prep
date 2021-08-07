class Solution {
public:
    vector<int> preprocess(string s){
        int len = s.size();
        vector<int> pi(len);
        pi[0] = 0;
        int j = 0;
        for (int i = 1; i < len; i++)
        {
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])
            {
                pi[i] = j + 1;
                j++;
            }
            else
            {
                pi[i] = 0;
            }
        }
        return pi;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m==0){
            return 0;
        }
        vector<int> pi = preprocess(needle);

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j]){
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                if (j == m - 1)
                {
                    return i-m+1;
                }
                else{
                    j++;
                }
            }
        }
        return -1;
    }
};
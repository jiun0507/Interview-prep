class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int palindrome[n][n];
        memset(palindrome, -1, sizeof(palindrome));
        for(int i = 0;i<n;i++){
            palindrome[i][i] = 1;
        }
        string ret = s.substr(0, 1);
        int start, end;
        start = 0;
        end = 1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==1 || (j+1<n&&j+i-1<n&&palindrome[j+1][j+i-1]==1)){
                    if(s[j]==s[j+i]){
                        palindrome[j][j+i]=1;
                        start = j;
                        end = i+1;
                    }
                }
            }
        }
        ret = s.substr(start, end);
        return ret;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_len = matrix.size();
        int col_len = matrix[0].size();
        bool dp[row_len][col_len];
        memset(dp, 0, sizeof(dp));
        int y = row_len-1;
        int x = col_len-1;
        while(true){
            if(target == matrix[y][x]) return true;
            else if(target<matrix[y][x]){
                dp[y][x] = true;
                bool moved = false;
                if(y>0){
                    y--;
                    moved = true;
                }
                if(x>0){
                    x--; moved = true;
                }
                if(!moved) return false;
            } else{
                if(y==row_len-1 && x == col_len-1) return false;
                if(y<row_len){
                    for(int j = 1;j+y<row_len;j++){
                        for(int i = 0;i<=x;i++){
                            if(dp[j+y][i]) break;
                            if(matrix[j+y][i]==target) return true;
                        }                            
                    }
                } 
                if(x<col_len){
                    for(int j = 1;j+x<col_len;j++){
                        for(int i = 0;i<=y;i++){
                            if(dp[i][j+x]) break;
                            if(matrix[i][j+x]==target) return true;
                        }
                    }
                }
                return false;
            }
        }
    }
};
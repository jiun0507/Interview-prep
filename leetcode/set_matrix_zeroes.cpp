// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool row = false;
        for(int i = 0;i<rows;i++){
            if(matrix[i][0] == 0){
                row = true;
            }
        }
        bool col = false;
        for(int i = 0;i<cols;i++){
            if(matrix[0][i] == 0){
                col = true;
            }
        }
        for(int i = 1;i<rows;i++){
            for(int j = 1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1;i<rows;i++){
            if(matrix[i][0]==0){
                for(int j = 1;j<cols;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1;j<cols;j++){
            if(matrix[0][j]==0){
                for(int i = 1;i<rows;i++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row){
            for(int i = 0;i<rows;i++){
                matrix[i][0] = 0;
            }
        }
        if(col){
            for(int j = 0;j<cols;j++){
                matrix[0][j] = 0;
            }
        }
        
    }
};
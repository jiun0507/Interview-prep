class Solution {
public:
    bool visited[10][10];
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {1, -1, 0, 0};

    bool start_find(vector<vector<char>>& board, int y, int x, string& word, int index){
        if(index == word.size()) return true;
        char cur = word.at(index);
        for(int i = 0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < board.size() && nx <board[0].size() && ny>=0 && nx>=0){
                if(!visited[ny][nx] && board[ny][nx] == cur){
                    visited[ny][nx] = true;
                    if(start_find(board, ny, nx, word, index+1)){
                        return true;
                    }
                    visited[ny][nx] = false;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        memset(visited, false, sizeof(visited));
    
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word.at(0)){
                    visited[i][j] = true;
                    if(start_find(board, i, j, word, 1)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
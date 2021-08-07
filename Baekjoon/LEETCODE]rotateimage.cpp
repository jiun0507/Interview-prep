class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dy[4] = {0, 1, 0, -1};
        int dx[4] = {1, 0, -1, 0};
        int n = matrix.size();
        for(int i = 0;i<n/2;i++){
            vector<int> temp(n-2*i-1, -1001);
            for(int k = 0;k<4;k++){
                int y, x, ny, nx;
                int nk = (k+1)%4;
                if(k==0){
                    y = x = i;                    
                } else if(k==1){
                    y = i;
                    x = n - 1 - i;
                } else if(k==2){
                    y = n - 1 - i;
                    x = n - 1 - i;
                } else if(k==3){
                    y = n - 1- i;
                    x = i;
                }
                if(nk==0){
                    ny = nx = i;                    
                } else if(nk==1){
                    ny = i;
                    nx = n - 1 - i;
                } else if(nk==2){
                    ny = n - 1 - i;
                    nx = n - 1 - i;
                } else if(nk==3){
                    ny = n - 1- i;
                    nx = i;
                }
                cout<<y<<" "<<x<<" "<<ny<<" "<<nx<<"\n";
                vector<int> temp2 = temp;
                for(int j = 0;j<n-2*i-1;j++){
                    cout<<j<<"attempt: "<<y<<" "<<x<<":"<<matrix[y][x]<<" "<<ny<<" "<<nx<<":"<<matrix[ny][nx]<<"\n";
                    temp2[j] = matrix[ny][nx];
                    if(temp[j]!=-1001){
                        matrix[ny][nx] = temp[j];     
                    } else{
                        matrix[ny][nx] = matrix[y][x];
                    }
                    y += dy[k];
                    x += dx[k];
                    ny += dy[nk];
                    nx += dx[nk];
                }   
                temp = temp2;
            }
        }
    }
};
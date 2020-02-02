//baekjoon 1080
//행렬

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int goal[50][50];
int given[50][50];
int main(void){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%1d", &given[i][j]);
            // cout<<given[i][j]<<" ";
        }
        // cout<<"\n";
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%1d", &goal[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0;i<n-2;i++){
        for(int j = 0;j<m-2;j++){
            if(given[i][j] != goal[i][j]){
                cnt++;
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        given[i+k][j+l]= 1-given[i+k][j+l];
                    }
                }
            }
        }
    }
    bool same = true;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(given[i][j] != goal[i][j]) same = false;
        }
    }
    if(!same){
        cout<<"-1"<<"\n";
    }
    else{
        cout<<cnt<<"\n";
    }
}

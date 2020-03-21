//baekjoon 12869
//뮤탈리스크
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int hp[3];
int d[61][61][61];
vector<int> attack;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    attack.push_back(1);
    attack.push_back(3);
    attack.push_back(9);
    for(int i = 0;i<3;i++){
        if(i>=n) hp[i] = 0;
        else{
            cin>>hp[i];
        }
    }
    
    // int a = 3>5 ? 1 :0;
    // cout<<a<<"\n";
    d[hp[0]][hp[1]][hp[2]] = 1;
    for(int i = 60;i>=0;i--){
        for(int j = 60;j>=0;j--){
            for(int k = 60;k>=0;k--){
                if(d[i][j][k] == 0) continue;
                do{
                    int ni = i - attack[0] > 0 ? i-attack[0] : 0;
                    int nj = j - attack[1] > 0 ? j - attack[1] : 0;
                    int nk = k - attack[2] > 0 ? k - attack[2] : 0;
                    if(d[ni][nj][nk] == 0 || d[ni][nj][nk] > d[i][j][k]+1){
                        d[ni][nj][nk] = d[i][j][k] + 1;    
                    }
                }while(next_permutation(attack.begin(),attack.end()));
                
            }
        }
    }
    cout<<d[0][0][0]-1<<"\n";
    
    return 0;

}
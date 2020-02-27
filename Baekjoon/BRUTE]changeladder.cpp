//baekjoon 15684
//사다리 조작
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,m,h;  
int ladder[30][35];

bool check_ladder(){
    for(int i = 1;i<=n;i++){
        int start = i;
        for(int j = 1;j<=h;j++){
            if(ladder[start][j]== 1){
                start++;
            }
            else if(ladder[start][j] == 2){
                start--;
            }
        }
        if(start!=i) return false;
    }
    return true;
}

int main(void){
     
    cin>>n>>m>>h;
    for(int i = 0;i<m;i++){
        int laddernum, line;
        cin>>laddernum>>line;
        ladder[line][laddernum] = 1;
        ladder[line+1][laddernum] = 2;
    }
    vector<pair<int,int>> ladders;
    for(int line1 = 1;line1<n;line1++){
        for(int ladder1 = 1;ladder1<=h;ladder1++){
            if(ladder[line1][ladder1]!=0 ||ladder[line1+1][ladder1]!=0) continue;
            ladders.push_back(make_pair(line1, ladder1));
        }
    }
    if(check_ladder()){
        cout<<"0\n";
        return 0;
    }
    int least = 4;
    int len = ladders.size();
    for(int i = 0;i<len;i++){
        auto p1 = ladders[i];
        int line1 = p1.first;
        int ladder1 = p1.second;
        if(least==1||ladder[line1][ladder1]!=0 ||ladder[line1+1][ladder1]!=0) continue;
        ladder[line1][ladder1] = 1;
        ladder[line1+1][ladder1]=2;
        if(check_ladder()){
            least = 1;
        } 
        for(int j = i+1;j<len;j++){
            auto p2 = ladders[j];
            int line2 = p2.first;
            int ladder2 = p2.second;
            if(least<=2 || ladder[line2][ladder2]!=0||ladder[line2+1][ladder2]!=0) continue;
            ladder[line2][ladder2] = 1;
            ladder[line2+1][ladder2]=2;
            if(check_ladder()){
                least = 2;
            } 
            for(int k = j+1;k<len;k++){
                auto p3 = ladders[k];
                int line3 = p3.first;
                int ladder3 = p3.second;
                if(least<=3 || ladder[line3][ladder3]!=0||ladder[line3+1][ladder3]!=0) continue;
                ladder[line3][ladder3] = 1;
                ladder[line3+1][ladder3]=2;
                if(least == 4 &&check_ladder()){
                    least = 3;
                } 
                ladder[line3][ladder3] = 0;
                ladder[line3+1][ladder3]= 0;
            
            }
            ladder[line2][ladder2] = 0;
            ladder[line2+1][ladder2]= 0;
        
        }
        ladder[line1][ladder1] = 0;
        ladder[line1+1][ladder1]= 0;
    }

    if(least == 4) cout<<"-1\n";
    else{
        cout<<least<<"\n";
    }
    return 0;
}
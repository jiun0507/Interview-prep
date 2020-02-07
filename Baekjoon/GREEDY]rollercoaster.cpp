//baekjoon 2873
//롤러코스터
//변이 한쪽이라도 홀수면 지그재그로 풀수 있음.
//둘다 짝수일때 스킵할 칸을 고르고 답을 찾음.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[3] = {-1, 1, 0};
int dx[3] = {0, 0, 1};

int main(void){
    int h, w;
    cin>>h>>w;
    string right, left, down, up;
    int smallest = 10000;
    int row, col;
    for(int i = 1;i<=h;i++){
        for(int j = 1;j<=w;j++){
            int temp;
            cin>>temp;
            if(temp< smallest && ((i+j) % 2) == 1){
                smallest =temp;
                row = i;
                col = j;
            } 
        }
    }
    // cout<<row<<" "<<col<<"\n";
    right = left = down = up = "";
    for(int i = 0;i<w-1;i++){
        right += 'R';
        left += 'L';
    }
    for(int i = 0;i<h-1;i++){
        down += 'D';
        up += 'U';
    }
    string downward = right + 'D' + left + 'D';
    string sideways = down + 'R' + up + 'R';
    string sideways2 = 'D' + left + 'D' + right;
    string ans = "";
    if(h % 2 == 1){
        for(int i = 0;i<h/2;i++){
            ans += downward;    
        }
        ans += right;
        cout<<ans<<"\n";
        return 0;
    }
    
    else if(w % 2 == 1){
        for(int i = 0;i<w/2;i++){
            ans += sideways;    
        }
        ans += down;
        cout<<ans<<"\n";
        return 0;
    }
    int goaly = h;
    int goalx = w;
    int starty = 1;
    int startx = 1;
    string first = "";
    string third = "";
    while(true){
        bool one = false;
        bool two = false;
        if(row<=starty+1){
            one = true;
        }
        else{
            first += downward;
            starty +=2;
        }
        if(goaly-1<=row){
            two= true;
        }
        else{
            third +=sideways2;
            goaly -=2;
        }
        if(one&&two) break;
    }
    string second1 = "";
    string second2 = "";
    while(true){
        bool one = false;
        bool two = false;
        if(col<=startx + 1){
            one = true;
        }
        else{
            // second1 += 'D'+'R'+'U'+'R';
            second1 += "DRUR";
            startx +=2;
        }
        if(goalx-1<=col){
            two= true;
        }
        else{
            // second2 += 'R'+'U'+'R'+'D';
            second2 += "RURD";
            goalx -=2;
        }
        if(one&&two) break;
    }
    if(row == starty){
        second1 += "DR";
    }
    else{
        second1 += "RD";
    }
    ans = first + second1 + second2+ third;
    cout<<ans<<"\n";
    // cout<<first<<"\n"<<second<<"\n"<<third;

}
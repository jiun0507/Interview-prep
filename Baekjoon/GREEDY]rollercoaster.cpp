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
    int check[3][w+1];
    memset(check, 0, sizeof(check));
    check[1][1] = 1;
    int dist = starty-1;
    goaly -= dist;
    row -= dist;
    starty = 1;
    check[row][col] = 1;

    string second = "";
    int cnt = 0;
    while(true){
        cnt ++;
        if((starty == goaly && startx == goalx) || cnt>3*w){
            break;
        }
        for(int i = 0;i<3;i++){
            int newy = starty + dy[i];
            int newx = startx + dx[i];
            if(newy>=1 && newy <=2 && newx >=1 && newx <=w && (row != newy || col != newy)){
                if(!check[newy][newx]){
                    check[newy][newx] = 1;
                    if(i == 0) second += 'U';
                    else if(i ==1) second += 'D';
                    else if(i ==2) second += 'R';
                    starty = newy;
                    startx = newx;
                    // cout<<starty<<" "<<startx<<"\n";
                    break;
                }
            }
        }
    }
    
    ans = first + second + third;
    cout<<ans<<"\n";
    // cout<<first<<"\n"<<second<<"\n"<<third;

}
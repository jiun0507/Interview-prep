// 퍼즐 1525
// baekjoon

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1, -1 ,0, 0};
int dx[4] = {0, 0, -1, 1};

int from_s_to_i(string s){
    return stoi(s);
}

int main(void)
{
    int n = 0;
    for(int i =100000000;i>=1;i/=10){
        int buf;
        cin>>buf;
        if(buf==0) buf = 9;
        n += buf*i;
    }
    map<int, int> check;
    check[n] = 0;
    queue<int> q;
    q.push(n);
    string test = to_string(n);
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(now == 123456789) break;
        string cur = to_string(now);
        int zero = cur.find("9");
        // cout<<cur<<" "<<zero<<endl;
        int y = zero/3;
        int x = zero%3;
        for(int i = 0;i<4;i++){
            int newy = dy[i] + y;
            int newx = dx[i] + x;
            if(newy>=0 && newy <=2 && newx >=0 && newx<=2){
                swap(cur[zero], cur[newy*3 + newx]);
                int int_version = stoi(cur);
                // cout<<int_version<<endl;
                if(check.find(int_version)==check.end()){
                    check[int_version] = check[now]+1;
                    q.push(int_version);
                }
                swap(cur[zero], cur[newy*3 + newx]);
            }
        }
    }
    if(check.find(123456789) != check.end()){
        cout<<check[123456789]<<endl;
    }
    else{
        cout<<"-1";
    }
    
    
    return 0;
}
//baekjoon6549
//히스토그램에서 가장 큰 직사각형

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long board[100001];
int main(void){
    int n;
    while(cin>>n){
        if(n == 0) break;
        for(int i = 0;i<n;i++){
            cin>>board[i];
        }
        stack<long long> s;
        long long mx = 0;
        for(int i = 0;i<n;i++){
            while(!s.empty() && board[s.top()]>board[i]){
                long long length = i;
                long long height = board[s.top()];
                s.pop();
                if(!s.empty()){
                    length = i-s.top()-1;
                }
                mx = max(mx, height*length);
            }
            mx = max(mx, board[i]);
            s.push(i);
        }
        while(!s.empty()){
            long long length = n;
            long long height = board[s.top()];
            s.pop();
            if(!s.empty()){
                length = length - s.top() - 1;
            }
            mx = max(mx, height*length);
        }

        cout<<mx<<"\n";
    }


}
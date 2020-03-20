//baekjoon 10942
//팰린드롬?
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m;
string str;
vector<int> num;
int palin[2001][2001];
bool go(int start, int end){
    if(start == end){
        palin[start][end] = 1;
        return true;  
    } 
    if(palin[start][end] != -1){
        return palin[start][end];
    }
    go(start, end-1);
    go(start +1, end);
    if(num[start] != num[end]){
        palin[start][end] = 0;
        return false;
    }
    else if(num[start] == num[end]){
        if(start + 1 == end){
            palin[start][end] = 1;
            return true;    
        } 
        else{
            palin[start][end] = palin[start+1][end-1];
            // palin[start][end] = go(start+1, end-1);
            return palin[start][end];
        }
    }
  
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0 ;i<n;i++){
        int buf;
        cin>>buf;
        num.push_back(buf);
    }
    memset(palin, -1, sizeof(palin));
    go(0, n-1);
    cin>>m;
    for(int i = 0;i<m;i++){
        int start, end;
        cin>>start>>end;
        
        if(palin[start-1][end-1] == 1){
            cout<<"1\n";
        } else{
            cout<<"0\n";
        }
    }
    return 0;

}
//baekjoon 1717
//집합의 표현

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int parent[1000001];
int rk[1000001];

int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
    
}

void Union(int y, int x){
    y = find(y);
    x = find(x);
    if (x == y) return;
    if (rk[x] < rk[y]) swap(x, y);
    
    parent[y] = x;
    if (rk[x] == rk[y]) {
        rk[x] = rk[y] + 1;
    // parent[x] = y;
    }
}

int main(void){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<=n;i++){
        parent[i] = i;
        // rk[i] = 0;
    }
    for(int i = 0;i<m;i++){
        int op, y, x;
        cin>>op>>y>>x;
        if(op == 0){
            Union(y, x);
        }
        else{
            if(find(x) == find(y)) cout<<"YES\n";
            else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}
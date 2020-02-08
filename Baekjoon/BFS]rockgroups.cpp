//baekjoon 12886
//돌 그룹
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int a,b,c;
int check[1501][1501];

bool go(int a, int b, int c, int sum){
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    check[a][b] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int aa = cur.first;
        int bb = cur.second;
        int cc = sum - aa -bb;
        int rocks[3] = {aa, bb, cc};
        if(aa==bb && bb == cc) return 1;
        int newa, newb;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(i == j) continue;
                if(rocks[i] > rocks[j]){
                    newa = rocks[i] - rocks[j];
                    newb = rocks[j] *2;
                    if(!check[newa][newb]){
                        check[newa][newb] = 1;
                        q.push(make_pair(newa, newb));
                    }
                }
            }
        }
    }
    return 0;
}


int main(){
    cin>>a>>b>>c;
    cout<<go(a,b,c, a+b+c);
    
    return 0;
}
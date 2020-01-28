// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int a,b,c;
int check[1501][1501];

// void go2(int y, int x){
// 	test[y][x] = 2;
// 	for(int i = 0;i<4;i++){
// 		int ny = y + dy[i];
// 		int nx = x + dx[i];
// 		if(check_range(ny ,nx)){
// 		    if(test[ny][nx] == 0){
// 		        go2(ny ,nx);
// 		    }
// 		}
// 	}
// 	return;
// }
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
        int rotation[3] = {aa, bb, cc};
        if(aa==bb && bb == cc) return 1;
        int newb, newa, newc;
        
        if(aa<bb){
            newb = bb-aa;
            newa = aa + aa;
            if(!check[newa][newb]){
                q.push(make_pair(newa, newb));
            }
        }
        if(aa>bb){
            newb = bb+bb;
            newa = aa-bb;
            if(!check[newa][newb]){
                q.push(make_pair(newa, newb));
            }
        }
        if(aa>cc){
            newc = cc+cc;
            newa = aa -cc;
            if(!check[newa][bb]){
                q.push(make_pair(newa, bb));
            }
        }
        if(aa<cc){
            newc = cc-aa;
            newa = aa + aa;
            if(!check[newa][bb]){
                q.push(make_pair(newa, bb));
            }
        }
        if(bb>cc){
            newc = cc+cc;
            newb = bb -cc;
            if(!check[aa][newb]){
                q.push(make_pair(aa, newb));
            }
        }
        if(bb<cc){
            newc = cc-bb;
            newb = bb+bb;
            if(!check[aa][newb]){
                q.push(make_pair(aa, newb));
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
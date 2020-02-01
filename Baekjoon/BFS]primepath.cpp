//baekjoon 1963
//소수경로
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int change(int num, int index, int digit) {
    if (index == 0 && digit == 0) return -1;
    string s = to_string(num);
    s[index] = digit+'0';
    return stoi(s);
}
bool can(int y, int x){
    int cnt = 0;
    for(int i = 0;i<4;i++){
        if((y%10) == (x%10)){
            cnt++;
        }
        y = y/10;
        x= x/10;
    }
    return cnt == 3;
}

int main(void){
    // cout<<can(1000, 1001)<<"\n";
    int n;
    cin>>n;
    while(n--){
        int f, t;
        cin>>f>>t;
        int check[10001] = {0};//check size up to you.(arbitrary)
    	for(int i=2;i<=10000;i++){
    		for(int j = i+i;j<=10000;j+=i){
    			check[j] = 1;
    		}
    	}
    
        int d[10001];	
        memset(d, -1, sizeof(d));
        
        d[f] = 0;
        queue<int> q;
        q.push(f);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == t) break;
            for (int i=0; i<4; i++) {
                for (int j=0; j<=9; j++) {
                    int next = change(cur, i, j);
                    if(d[next] != -1 || check[next]) continue;
                    if(!can(cur, next)) continue;
                    q.push(next);
                    d[next] = d[cur] + 1;
                }
            }    
        }
        if(d[t] == -1){
            cout<<"Impossible"<<"\n";
        }
        else{
    	    cout<<d[t]<<"\n";
        }
    }
    
        
}

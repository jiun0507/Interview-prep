//baekjoon 1963
//소수경로

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

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
            for(int i = 1000;i<10000;i++){
                if(d[i] != -1 || check[i]) continue;
                if(!can(cur, i)) continue;
                q.push(i);
                d[i] = d[cur] + 1;
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
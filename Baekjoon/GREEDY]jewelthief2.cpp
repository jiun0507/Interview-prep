//baekjoon 1202
//보석도둑
//using priority_queue

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,k;

struct jewel{
    int m,v, w;
};
bool compare(jewel &a, jewel &b){
    return a.m < b.m || (a.m == b.m && a.w < b.w);
}
int main(void){
    
    cin>>n>>k;
    vector<jewel> jewels(n+k);
    cin.ignore();
    for(int i = 0;i<n;i++){
        scanf("%d %d",&jewels[i].m,&jewels[i].v);
    }
    for(int i = n;i<k+n;i++){
        scanf("%d",&jewels[i].m);
        jewels[i].w = 1;
    }
    sort(jewels.begin(), jewels.end(), [](jewel u, jewel v) {
        return u.m < v.m || (u.m == v.m && u.w < v.w);
    });
    priority_queue<int> q;
    long long ans = 0;
    for(auto &p: jewels){
        if(p.w == 0){
            q.push(p.v);
        }
        else{
            if(!q.empty()){
                ans += (long long)q.top();
                q.pop();    
            }
            
        }
    }
    printf("%lld\n", ans);
    return 0;
}
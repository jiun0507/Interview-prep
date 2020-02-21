//baekjoon 17089
//세 친구
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

int n, m;

int friends[4010][4010];
int numf[4010]={0};
int chosen[3]={-1};

int go(vector<vector<int>> &friendslist, int person, int cnt){
    if(cnt==3){
        int result = numf[chosen[0]]+numf[chosen[1]]+numf[chosen[2]];
        if(friends[chosen[0]][chosen[2]]) return result-6;
        return -1;  
    } 
    int ans = -1;
    for(int frd:friendslist[person]){
        if((chosen[0]==-1||chosen[0]!=frd)&&(chosen[1]==-1||chosen[1]!=frd)){
            chosen[cnt] = frd;
            int temp = go(friendslist, frd, cnt+1);
            if(temp!=-1){
                if(ans==-1||ans>temp) ans = temp;
            }
            chosen[cnt] = -1;
        }
    }

    return ans;
}

int main(void){
    cin>>n>>m;
    memset(chosen,-1, sizeof(chosen));
    memset(numf,0,sizeof(numf));
    vector<vector<int>> friendslist(n+1);
    for(int i = 0;i<m;i++){
        int fx, fy;
        cin>>fx>>fy;
        numf[fx]+=1;
        numf[fy]+=1;
        friendslist[fx].push_back(fy);
        friendslist[fy].push_back(fx);
        friends[fx][fy]=1;
        friends[fy][fx]=1;
    }
    int ans = -1;
    for(int i = 1;i<=n;i++){
        chosen[0] = i;
        int temp = go(friendslist, i, 1);
        if(temp != -1){
            if(ans==-1||ans>temp) ans = temp;
        }
        chosen[0] = -1;
    }
    cout<<ans<<"\n";

}
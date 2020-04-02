//baekjoon 1970
//건배

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int d[1001][1001];
int num[1001];

int go(int i, int j){
    if(i>=j){
        return 0;
    }
    int &ans = d[i][j];
    if(ans != -1){
        return ans;
    }
    
    ans = go(i+1, j);
    for(int k = i+1;k<=j;k+=1){
        if(num[i] != num[k]) continue;
        int temp =  go(i+1, k-1) + go(k+1, j) + 1;
        
        if(ans<temp) ans = temp;
    }
    
    return ans;
    
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }

    memset(d, -1, sizeof(d));
    int ans = go(0, n-1);
    cout<<ans<<"\n";
    return 0;
}

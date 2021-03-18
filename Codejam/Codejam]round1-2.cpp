// Pascal walk
// a OK
// b OK
// c OK
// a => 그냥 옆선만 따라 가도 해결
// b => 옆선 따라가다 한번 꺾어주기만 해도 해결
// c => n-30을 이진수로 표현. row가 check되어 있으면 horizontally 가로지름. 계속 내려감. 
// 부족한 숫자만큼 다 끝난뒤 옆선을 따라서 계속 움직임. 


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int pascal[501][501];
int n;

int main()
{
    int t;
    cin>>t;
    int ct = 1;
    while(t--){
        cout<<"Case #"<<ct++<<":\n";
        cin>>n;
        if(n<=30){
            for(int i = 1;i<=n;i++){
                cout<<i<<" "<<1<<"\n";
            }
            continue;
        }
        n -=30;
        int bitmask[31];
        memset(bitmask, -1, sizeof(bitmask));

        int ind = 1;
        while(n!=0){
            bitmask[ind++] = n%2;
            n /= 2;
        }

        bool left = 1;
        int cnt = 30;
        vector<pair<int,int>> ans;
        for(int i = 1;i<=30;i++){
            if(bitmask[i]==1){
                for(int j = 1;j<=i;j++){
                    if(left){
                        ans.push_back(make_pair(i, j));
                    } else{
                        ans.push_back(make_pair(i, i-j+1));
                    }
                }
                left = 1 - left;
            }
            else{
                if(left) ans.push_back(make_pair(i, 1));
                else{
                    ans.push_back(make_pair(i, i));
                }
                cnt -= 1;
            }
        }
        for(int i = 1;i<=cnt;i++){
            if(left){
                ans.push_back(make_pair(30+i, 1));
            }
            else{
                ans.push_back(make_pair(30+i, 30+i));
            }
        }
        for(auto c:ans){
            cout<<c.first<<" "<<c.second<<"\n";
        }

    }
    return 0;
}

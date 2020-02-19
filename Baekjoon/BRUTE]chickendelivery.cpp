//baekjoon 15686
//치킨 배달
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int n,m;
vector<pair<int,int>> houses;
vector<pair<int,int>> chickens;
int town[50][50];

vector<int> makevec(int bit){
    vector<int> ans;
    for(int i = 0;i<chickens.size();i++){
        ans.push_back(bit&1);
        bit >>=1;
    }
    return ans;
}

int main(void){
   cin>>n>>m;
   for(int i = 0;i<n;i++){
       for(int j = 0;j<n;j++){
           cin>>town[i][j];
           if(town[i][j] == 1){
               houses.push_back(make_pair(i,j));
           }
           if(town[i][j] == 2){
               chickens.push_back(make_pair(i,j));
           }
       }
   }
   int ans = -1;
   for(int i = 0;i<(1<<chickens.size());i++){
       vector<int> keep = makevec(i);
       int cnt = 0;
        for(int j = 0;j<chickens.size();j++){ 
            if(keep[j]==1) cnt++;
        }
        if(cnt!=m) continue;
        int chickendistance = 0;
        for(int j = 0;j<houses.size();j++){
            int house_chicken =-1;
            int housey = houses[j].first;
            int housex = houses[j].second;
            for(int k = 0;k<chickens.size();k++){
                if(keep[k] == 1){
                    int dist = abs(housey-chickens[k].first) + abs(housex - chickens[k].second);
                    if(house_chicken ==-1||house_chicken>dist) house_chicken = dist;
                }
            }
            chickendistance += house_chicken;
        }
        if(ans==-1|ans>chickendistance) ans = chickendistance;
   }
   cout<<ans<<"\n";
    
}

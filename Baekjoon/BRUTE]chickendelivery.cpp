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
   vector<int> d(chickens.size());
   for(int i = 0;i<m;i++){
       d.push_back(1);
   }
   for(int i = 0;i<chickens.size()-m;i++){
       d.push_back(0);
   }
   sort(d.begin(),d.end());
   int ans = -1;
   do{
       int cnt = 0;
        for(int j = 0;j<chickens.size();j++){ 
            if(d[j]==1) cnt++;
        }
        if(cnt!=m) continue;
        int chickendistance = 0;
        for(int j = 0;j<houses.size();j++){
            int house_chicken =-1;
            int housey = houses[j].first;
            int housex = houses[j].second;
            for(int k = 0;k<chickens.size();k++){
                if(d[k] == 1){
                    int dist = abs(housey-chickens[k].first) + abs(housex - chickens[k].second);
                    if(house_chicken ==-1||house_chicken>dist) house_chicken = dist;
                }
            }
            chickendistance += house_chicken;
        }
        if(ans==-1|ans>chickendistance) ans = chickendistance;
   }while(next_permutation(d.begin(), d.end()));
   cout<<ans<<"\n";
    
}
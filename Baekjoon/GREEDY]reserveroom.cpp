//회의실 배정
//baekjoon 1931
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int coin[100];
vector<pair<int,int>> d;
int main(void){
    cin>>n;
    for(int i = 0;i<n;i++){
        int y, x;
        cin>>y>>x;
        d.push_back(make_pair(x, y));
    }
    sort(d.begin(), d.end());
    // for(int i = 0;i<d.size();i++){
    //     cout<<d[i].first<<" "<<d[i].second<<"\n";
    // }
    int cnt = 0;
    int end = 0;
    for(int i = 0;i<n;i++){
        if(d[i].second>end){
            end = d[i].first;
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

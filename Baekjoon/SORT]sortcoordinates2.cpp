//baekjoon 11651
//좌표 정렬2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool cmp_y(pair<int,int> &u, pair<int,int> &v){
    if(u.second<v.second){
        return true;
    }else{
        if(u.second == v.second){
            return u.first <v.first;
        }    
        return false;
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i =0;i<n;i++){
        int first, second;
        cin>>first>>second;
        a[i] = make_pair(first, second);
    }
	sort(a.begin(), a.end(), cmp_y);
    for(int i =0;i<n;i++){
        cout<<a[i].first<<" "<<a[i].second<<"\n";
    }
}
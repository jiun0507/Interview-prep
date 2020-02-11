//baekjoon 11650
//좌표 정렬하기

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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
	sort(a.begin(), a.end());
    for(int i =0;i<n;i++){
        cout<<a[i].first<<" "<<a[i].second<<"\n";
    }
}
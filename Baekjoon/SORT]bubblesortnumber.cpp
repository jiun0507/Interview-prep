//baekjoon 1377
//버블소트
//그냥 버블소트하는 문제는 아니다.
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
        int temp;
        cin>>temp;
        a[i].first = temp;
        a[i].second = i;
    }
	sort(a.begin(), a.end());
	int cnt = 0;
	for(int i =0;i<n;i++){
        if(a[i].second-i>cnt){
            cnt = a[i].second-i;
        }
    }
    cout<<cnt+1<<"\n";
    return 0;
}
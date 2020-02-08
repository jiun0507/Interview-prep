//baekjoon 10815
//숫자카드
//cin.tie(nullptr) 중요 ->타임오버 방지
#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }
    sort(num.begin(),num.end());

    int k;
    cin>>k;
    for(int i = 0;i<k;i++){
        int x;
        cin>>x;
        int left = 0;
        int right = n-1;
        int middle;
        int ans = 0;
        while(left<=right){
            int middle = (left + right)/2;
            if(num[middle] == x){
                ans = 1;
                break;
            }
            else if(num[middle]<x){
                left = middle +1;
            }
            else if(num[middle]>x){
                right = middle -1;
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}

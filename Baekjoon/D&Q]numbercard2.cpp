//baekjoon 10816
//숫자카드 2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
int num[1000000];
int lowerbound(int x){
    int left = 0;
    int right = n-1;
    int middle;
    int ans = -1;
    while(left<=right){
        int middle = (left + right)/2;
        if(num[middle] == x){
            ans = middle;
            right = middle -1;
        }
        else if(num[middle]<x){
            left = middle +1;
        }
        else if(num[middle]>x){
            right = middle -1;
        }
    }
    return ans;
}

int upperbound(int x){
    int left = 0;
    int right = n-1;
    int middle;
    int ans = -1;
    while(left<=right){
        int middle = (left + right)/2;
        if(num[middle] == x){
            ans = middle + 1;
            left= middle + 1;
        }
        else if(num[middle]<x){
            left = middle +1;
        }
        else if(num[middle]>x){
            right = middle -1;
        }
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num + n);

    int k;
    cin>>k;
    for(int i = 0;i<k;i++){
        int x;
        cin>>x;
        int low = lowerbound(x);
        int up = upperbound(x);
        if(low == -1) cout<<"0 ";
        else{
            cout<<up - low<<" ";
        }
    }
    return 0;
}
//baekjoon 2751
//정렬
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int quick(int start, int end){
    int middle = (start+end)/2;
    int k = a[middle];
    int loc = start;
    swap(a[middle],a[end]);
    for(int i = start;i<end;i++){
        if(a[i] <k){
            swap(a[loc],a[i]);
            loc++;
        }
    }
    swap(a[loc], a[end]);
    return loc;
}

void solve(int start, int end){
    if(start< end){
        int pivot = quick(start, end);
        solve(start, pivot-1);
        solve(pivot+1, end);
        
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
	solve(0, n-1);
    for(int i =0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
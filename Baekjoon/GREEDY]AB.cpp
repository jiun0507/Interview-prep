//baekjoon 12970
//AB

//A와B각각 a, b개씩 있으면 0~a*b의 (i,j)페어 만들수 있다.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n,k;
    cin>>n>>k;
    string s = "";
    int sum = 0;
    for(int a = 0;a<=n;a++){
        int b = n-a;
        if(a*b<k) continue;
        vector<int> ans(b+1);
        for(int i = 0;i<a;i++){
            int x = min(b, k);
            ans[x] += 1;
            k -=x;
        }
        for(int i = b; i>=0;i--){
            for(int j = 0;j<ans[i];j++){
                cout<<"A";
            }
            if(i != 0){
                cout<<"B";
            }
        }
        cout<<"\n";
        return 0;
    }
    cout<<"-1\n";
    return 0;
    
}
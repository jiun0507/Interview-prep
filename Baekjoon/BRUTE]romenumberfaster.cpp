//baekjoon 16922
//로마숫자
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

bool check[1010];
int rome[4] = {1, 5, 10, 50};
int n;

int main(void){
    
    cin>>n;
    int ans = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n-i;j++){
            for(int k = 0;k<=n-i-j;k++){
                int l = n-i-j-k;
                if(l>=0){
                    int sum = rome[0] * i + rome[1] * j + rome[2] * k+ rome[3] * l;
                    if(!check[sum]){
                        ans +=1; 
                        check[sum] = true;
                    } 
                }
            }   
        }   
    }
    cout<<ans<<"\n";
}

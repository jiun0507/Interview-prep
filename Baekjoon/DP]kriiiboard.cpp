//baekjoon 11058
//크리보드

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long d[110];//문제에 굳이 제한이 안 나와있더라도 정황상 long long이 필요하면 long long으로 해주기

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n<=3){
        cout<<n<<"\n";
        return 0;
    }
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    for(int i = 4;i<=n;i++){
        d[i] = d[i-1] + 1;
        for(int j =1; j<=i-3;j++){
            d[i] = max(d[i], d[i-(j+2)] * (j+1));
            //max도 long long에 사용가능.
        }
    }
    cout<<d[n]<<"\n";
}

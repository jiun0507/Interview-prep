//baekjoon 3012
//올바른 괄호 문자열

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long d[201][201];
int num[201];
long long mod = 100000;
long long calculate(int i, int j){
    int a = num[i];
    int b = num[j];
    if(a>3 || (b!=0 && b <4)) return 0;
    if(a == 0 || b == 0){
        if(a == 0 && b == 0) return 3;
        else{
            return 1;
        }
    }
    if(a+3 == b) return 1;
    return 0;
    
}

long long go(int i, int j){
    if(i-1 == j){
        return 1;
    }
    long long &ans = d[i][j];
    if(ans != -1){
        // cout<<i<<" "<<j<<"\n";
        return ans;
    }

    ans = 0;
    for(int k = i+1;k<=j;k+=2){
        if(calculate(i, k) == 0) continue;
        long long temp = calculate(i, k) * go(i+1, k-1) * go(k+1, j);
        ans += temp;

        //그냥 mod로 나누는게 아니고 뒤의 다섯자리만 계속 바꿔주는 것.
        if (ans >= mod) {
            ans = mod + ans % mod;
        }
    }
    
    return ans;
    
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    string str;
    cin>>str;
    for(int i = 0;i<str.size();i++){
        if(str.at(i) == '(') num[i] = 1;
        else if(str.at(i) == '{') num[i] = 2;
        else if(str.at(i) == '[') num[i] = 3;
        else if(str.at(i) == ')') num[i] = 4;
        else if(str.at(i) == '}') num[i] = 5;
        else if(str.at(i) == ']') num[i] = 6;
        else if(str.at(i) == '?') num[i] = 0;
    }

    memset(d, -1, sizeof(d));
    long long ans = go(0, n-1);
    if (ans >= mod) {
        //뒤의 다섯자리만 프린트 해줌
        printf("%05lld\n",ans%mod);
    } else {
        printf("%lld\n",ans);
    }
    return 0;
}

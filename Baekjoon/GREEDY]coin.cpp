//baekjoon 11047
//코인0
#include <iostream>
using namespace std;

int n,k;
int coin[100];
int main(void){
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>coin[i];
    }
    int cnt = 0;
    for(int i = n-1;i>=0;i--){
        cnt += k/coin[i];
        k%=coin[i];
    }
    cout<<cnt<<"\n";
}


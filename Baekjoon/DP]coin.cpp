//baekjoon 2293
//동전 1
#include <iostream>
using namespace std;

int n, k;
int num[101];
int d[10001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>num[i];   
    }
    d[0] = 1;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=k;j++){
            if(j - num[i] >=0){
                 d[j] += d[j-num[i]];
            }
        }
    }
    cout<<d[k]<<"\n";
}

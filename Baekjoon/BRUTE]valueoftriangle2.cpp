//baekjoon 4902
//삼각형의 값
//calc함수로 해결하는 방식
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
int triangle[410][900];
int sum[410][900];
int ans = 0;

void calc(int row, int left, int right, int summed){
    if(row<1 || row>n) return;
    if(left<1 || right>row*2-1) return;
    summed += sum[row][right] - sum[row][left-1];
    if(ans<summed) ans = summed;
    if(left%2==0){
        calc(row-1, left-2, right, summed);
    }
    else{
        calc(row+1, left, right+2, summed);
    }
    
}

int main(void){
    int tc = 1;
    while(true){
        ans = INT_MIN;
        cin>>n;
        if(n==0) break;
        memset(sum, 0, sizeof(sum));
        memset(triangle, 0, sizeof(triangle));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=2*i-1;j++){
                cin>>triangle[i][j];
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=2*i-1;j++){
                sum[i][j] =triangle[i][j];
                if(j>1) sum[i][j] += sum[i][j-1];
                // cout<<sum[i][j]<<" ";
            }
            // cout<<"\n";
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i*2-1;j++){
                calc(i,j,j,0);
            }
        }
        cout<<tc<<". "<<ans<<"\n";
        tc++;
    }
    
}
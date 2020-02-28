//baekjoon 4902
//삼각형의 값
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
int triangle[410][900];
int sum[410][900];

int main(void){
    int tc = 1;
    while(true){
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
                cout<<sum[i][j]<<" ";
            }
            cout<<"\n";
        }
        // cout<<triangle[3][5]<<"\n";
        int ans = INT_MIN;
        for(int i = 1;i<=n;i++){
            //starting column of the triangle.
            for(int j = 1;j<=2*i-1;j++){
                if(j%2==0) continue;
                int add = 0;
                for(int level = 1;level<=n-i+1;level++){
                    add += sum[i-1+level][j-1+(2*level-1)];
                    if(j!=1) add -= sum[i-1+level][j-1];
                    // cout<<i<<" "<<j<<" "<<level<<" "<<add<<"\n";
                    ans = max(ans, add);
                }
                
            }
        }
        for(int i = n;i>=1;i--){
            for(int j = 1;j<=2*i-1;j++){
                if(j%2==1) continue;
                int add = 0;
                for(int level = 1; level< i-(j-1)/2 && level<=(j+1)/2;level++){
                    add += sum[i+1-level][j];
                    add -= sum[i+1-level][j-2*level+1];
                    // cout<<i<<" "<<j<<" "<<level<<" "<<add<<"\n";
                    ans = max(ans, add);
                }
                
            }
        }
        cout<<tc<<". "<<ans<<"\n";
        tc++;
    }

}
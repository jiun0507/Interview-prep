//kakaofriends
//https://www.acmicpc.net/status?user_id=jiun9605&problem_id=15954&from_mine=1
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k;
vector<pair<int,int>> d;
int pop[500], cumu[500];
int main(void){
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>pop[i];
        cumu[i] = pop[i];
        if(i!=0) cumu[i] += cumu[i-1];
    }
    double least = 10000000.0;
    for(int l =k;l<=n;l++){
        for(int i = 0;i<=n-l;i++){
            // cout<<i<<"\n";
            double mean = 0.0;
            if(i ==0) mean = (double)cumu[i+l-1];
            else{
                mean = (double)(cumu[i+l-1]-cumu[i-1]);    
            }
            mean /=(double)l;
            double sq = 0.0;
            for(int j = 0;j<l;j++){
                sq += pow(((double)pop[i+j])-mean, (double)2.0);
            }
            // printf("%lf\n", sq/(double)l);
            double variance = sqrt(sq/(double)l);
            // cout<<variance<<"\n";
            if(least>variance){
                least = variance;
            }
        }    
    }
  
    printf("%.11lf\n", least);
    
}


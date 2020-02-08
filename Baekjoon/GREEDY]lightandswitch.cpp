//baekjoon 2139
//전구와 스위치
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int goal[100000];
int given[100000];
int given2[100000];
int main(void){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        scanf("%1d",&given[i]);
        given2[i] = given[i];
    }
    for(int i = 0;i<n;i++){
        scanf("%1d",&goal[i]);
    }
    given[0] = (given[0]+1)%2;
    given[1] = (given[1]+1)%2;
    int cnt = 1;
    int cnt2 = 0;
    for(int i = 1;i<n;i++){
        if(given[i-1] != goal[i-1]){
            cnt++;
            given[i-1] = (given[i-1]+1)%2;
            given[i] = (given[i]+1)%2;
            if(i+1<n){
                given[i+1] = (given[i+1]+1)%2;
            }
        }
       if(given2[i-1] != goal[i-1]){
           cnt2++;
            given2[i-1] = (given2[i-1]+1)%2;
            given2[i] = (given2[i]+1)%2;
            if(i+1<n){
                given2[i+1] = (given2[i+1]+1)%2;
            }
        }
    }
    bool same =true;
    bool same2= true;
    for(int i = 0;i<n;i++){
        if(goal[i]!= given[i]) same = false;
        if(goal[i]!=given2[i]) same2= false;
    }
    if(same && same2){
        cout<<min(cnt, cnt2)<<"\n";
    }
    else if(same) cout<<cnt<<"\n";
    else if(same2) cout<<cnt2<<"\n";
    else{
        cout<<"-1"<<"\n";
    }
}

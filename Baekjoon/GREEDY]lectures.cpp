//baekjoon 2109
//순회강연
//보석도둑이랑 비슷하지만 반대의 문제. 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,k;

struct lecture{
    int pay, due, day;
};

int main(void){
    
    scanf("%d",&n);
    int latest =0;
    vector<lecture> lectures(n);
    for(int i = 0;i<n;i++){
        scanf("%d %d",&lectures[i].pay, &lectures[i].due);
        if(lectures[i].due>latest) latest = lectures[i].due;
    }
    for(int i = 1;i<= latest;i++){
        lecture temp;
        temp.due = i;
        temp.day = 1;
        lectures.push_back(temp);
    }

    sort(lectures.begin(), lectures.end(), [](lecture u, lecture v) {
        return u.due > v.due || (u.due == v.due && u.day < v.day);
    });

    
    priority_queue<int> q;
    long long ans = 0;
    for(auto &p: lectures){
        if(p.day == 0){
            q.push(p.pay);
        }
        else{
            if(!q.empty()){
                // cout<<q.top()<<"\n";
                ans += (long long)q.top();
                q.pop();
            }
            
        }
    }
    printf("%lld\n", ans);
    return 0;
}
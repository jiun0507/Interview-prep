

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char direction[4] = {'E', 'S', 'W', 'N'};
const int INF = 1000000000;

int find(stack<int> &dirs, long long x, long long y, int count){
    if(count>30){
        return INF;
    }
    if(y==0&&x==0){
        return 0;
    }
    long long nx = x%2;
    long long ny = y%2;
    if(nx==0&&ny==0){
        return INF;
    }
    else if(nx==1&&ny==1){
        return INF;
    }
    int ret = INF;
    int cur = INF;
    if(nx==1){
        if(dirs.empty()||(2-dirs.top()!=0)){
            dirs.push(0);
            int temp = find(dirs, x/2, y/2, count+1)+1;
            if(temp<ret){
                ret = temp;
                cur = 0;
            }
            dirs.pop();
        }
        if(dirs.empty()||(2-dirs.top()!=2)){
            dirs.push(2);
            int temp = find(dirs, (x+1)/2, y/2, count+1)+1;
            if(temp<ret){
                ret = temp;
                cur = 2;
            }
            dirs.pop();
        }
    } else if(ny==1) {
        if(dirs.empty()||(4-dirs.top()!=3)){
            dirs.push(3);
            int temp = find(dirs, x/2, y/2, count+1)+1;
            if(temp<ret){
                ret = temp;
                cur = 3;
            }
            dirs.pop();
        }
        if(dirs.empty()||(4-dirs.top()!=1)){
            dirs.push(1);
            int temp = find(dirs, x/2, (y+1)/2, count+1)+1;
            if(temp<ret){
                ret = temp;
                cur = 1;
            }
            dirs.pop();
        }
    }
    if(ret != INF){
        dirs.push(cur);
        return ret;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    int cnt = 1;
    while(t--){
        cout<<"Case #"<<cnt++<<": ";
        long long x, y;
        bool upside = false;
        bool leftside= false;
        cin>>x>>y;
        if(x<0){
            leftside = true;
            x *=-1;
        }
        if(y<0){
            upside = true;
            y *=-1;
        }
        stack<int> ans;
        int ret = find(ans, x, y, 0);
        if(ret != INF){
            vector<int> real_ans;
            while(!ans.empty()){
                real_ans.push_back(ans.top());
                ans.pop();
            }
            reverse(real_ans.begin(), real_ans.end());
            for(auto a:real_ans){
                if(upside&&(a==1||a==3)){
                    a = 4-a;
                } 
                else if(leftside&&(a==0||a==2)){
                    a = 2-a;
                }
                if(a<0||a>=4){
                    continue;
                }
                cout<<direction[a];
            }
            cout<<"\n";
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
    }

    return 0;
}

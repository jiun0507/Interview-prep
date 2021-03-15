

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char direction[4] = {'E', 'S', 'W', 'N'};

bool find(stack<int> &dirs, long long x, long long y, int count){
    // cout<<"\n"<<x<<" "<<y<<"\n";
    if(count>30){
        return false;
    }
    if(y==0&&x==0){
        return true;
    }
    long long nx = x%2;
    long long ny = y%2;
    if(nx==0&&ny==0){
        return false;
    }
    else if(nx==1&&ny==1){
        return false;
    }
    if(nx==1){
        if(dirs.empty()||(2-dirs.top()!=0)){
            dirs.push(0);
            if(find(dirs, x/2, y/2, count+1)){
                return true;
            }
            dirs.pop();
        }
        if(dirs.empty()||(2-dirs.top()!=2)){
            dirs.push(2);
            if(find(dirs, (x+1)/2, y/2, count+1)){
                return true;
            }
            dirs.pop();
        }
    } else if(ny==1) {
        if(dirs.empty()||(4-dirs.top()!=3)){
            dirs.push(3);
            if(find(dirs, x/2, y/2, count+1)){
                return true;
            }
            dirs.pop();
        }
        if(dirs.empty()||(4-dirs.top()!=1)){
            dirs.push(1);
            if(find(dirs, x/2, (y+1)/2,count+1)){
                return true;
            }
            dirs.pop();

        }
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
        if(find(ans, x, y, 0)){
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
            // cout<<" "<<x<<" "<<y<<"\n";
            cout<<"\n";
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
    }

    return 0;
}

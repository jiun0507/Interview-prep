

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char direction[4] = {'E', 'S', 'W', 'N'};

bool find(stack<int> &dirs, long long x, long long y){
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
        dirs.push(0);
        if(find(dirs, x/2, y/2)){
            return true;
        }
        dirs.pop();
        dirs.push(2);
        if(find(dirs, (x+1)/2, y/2)){
            return true;
        }
        dirs.pop();
    } else if(ny==1) {
        dirs.push(3);
        if(find(dirs, x/2, y/2)){
            return true;
        }
        dirs.pop();
        dirs.push(1);
        if(find(dirs, x/2, (y+1)/2)){
            return true;
        }
        dirs.pop();
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    int a, b;
    cin>>a>>b;
    while(true){
        cout<<1<<" "<<1<<"\n";
        string response;
        cin>>response;
    }

    return 0;
}

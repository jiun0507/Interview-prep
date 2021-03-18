

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void set1(){
    string response;
    bool found = false;
    for(int i = -5;i<=5;i++){
        for(int j = -5;j<=5;j++){
            cout<<i<<" "<<j<<endl;
            cout.flush();
            cin>>response;
            if(response=="CENTER"){
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(!found){
        cout<<1000000001<<" "<<1000000001<<endl;
        cout.flush();
    }
    return ;
}

int main()
{
    int t, a, b;
    cin>>t;
    cin>>a>>b;
    while(t--){
        set1();
    }
    return 0;
}

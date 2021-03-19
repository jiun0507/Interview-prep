

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int a, b;
    int cnt = 1;
    while(t--){
        cin>>a>>b;
        cout<<"Case #"<<cnt++<<": ";
        cout<<(a-1)*(b-1)<<"\n";
        for(int i =a;i>=2;i--){
            for(int j = 1;j<b;j++){
                cout<<i<<" "<<(i*(b-2))+i-j<<"\n";
            }
        }
    }

    return 0;
}

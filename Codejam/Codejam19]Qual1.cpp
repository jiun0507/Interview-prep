

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int cnt =1 ;
    while(t--){
        cout<<"Case #"<<cnt++<<": ";
        string n;
        cin>>n;
        stack<char> a;
        stack<char> b;  
        for(int i = n.size()-1;i>=0;i--){
            if(n[i]=='4'){
                b.push('1');
                a.push('3');
            } else{
                b.push('0');
                a.push(n[i]);
            }
        }
        while(!a.empty()){
            cout<<a.top();
            a.pop();
        }
        cout<<" ";
        bool start = false;
        while(!b.empty()){
            if(b.top()=='0'){
                if(start){
                    cout<<b.top();
                }
                b.pop();
            } else{
                start = true;
                cout<<b.top();
                b.pop();
            }
        }
        cout<<"\n";
    }


    return 0;
}

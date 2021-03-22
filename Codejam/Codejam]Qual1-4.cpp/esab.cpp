

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

const int mx = 1000000000;
string file_path = "output.txt";
ofstream writeFile(file_path.data());

string set1(){
    for(int i = 0;i<140;i++){
        cout<<1<<"\n";
        string response;
        cin>>response;
    }
    string ans = "";
    for(int i =1;i<=10;i++){
        string buf;
        cout<<i<<"\n";
        cin>>buf;
        ans += buf;
    }
    return ans;
}

string set2(){
    string a[2] = {"", ""};
    string b[2] = {"", ""};
    for(int i =0;i<10;i++){
        // cout<<i<<"\n";
        string buf;
        cin>>buf;
        a[0] += buf;
        a[1] += to_string('1'-a[0][i]);
    }
    for(int i = 0;i<14;i++){
        string check= "";
        for(int j =1;j<=10;j++){
            //cout<<j<<"\n";
            string buf;
            cin>>buf;
            check += buf;
        }
        if(check==a[0] || check==a[1]) continue;
        b[0] = check;
    }
    if(b[0]==""){
        b[0] = a[0];
        b[1] = a[1];
    }
    else{
        for(int i = 0;i<10;i++){
            b[1] += to_string('1'-b[0][i]);
        }
    }
    reverse(b[0].begin(), b[0].end());
    reverse(b[1].begin(), b[1].end());

    for(int i = 0;i<2;i++){
        cout<<"A"<<a[i]<<"\n";
        cout<<"B"<<b[i]<<"\n";
    }
    int left_a = 0;
    int left_b = 0;
    int right_a = 0;
    int right_b = 0;

    cout<<1<<"\n";
    char response;
    cin>>response;
    if(a[0][0]==response){
        left_a = 1;
    } else if(a[1][0]==response){
        left_a = 2;
    }
    if(b[0][0]==response){
        left_b = 1;
    } else if(b[1][0]==response){
        left_b = 2;
    }


    return "1";
}

int main()
{
    int t, b;
    // for(int i = 0;i<3;i++){
    cin>>t>>b;
    while(t--){
        cout<<set2()<<"\n";
        string result;
        cin>>result;
        if(result=="N") break;
    }
    // if(writeFile.is_open()){
    //     writeFile<<"next:"<<to_string(t)<<"\n";
    // }   
    return 0;
}



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
        cout<<i<<"\n";
        string buf;
        cin>>buf;
        a[0] += buf;
    }
    string opposite = "";
    for(int i = 0;i<10;i++){
        a[1] += to_string('1'-a[0][i]);
    }
    for(int i = 0;i<12;i++){
        string check= "";
        for(int j =0;j<10;j++){
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
        string opposite = "";
        for(int i = 0;i<10;i++){
            b[1] += to_string('1'-b[0][i]);
        }
    }


}

int main()
{
    int t, a, b;
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

//baekjoon 16968
//차량번호판 1
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin>>input;
    
    int num = 1;
    char prev = 'e';
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == prev){
            if(input[i] == 'c') num *= 26 -1;
            else{
                num *= 10-1;
            }
        }
        else{
            if(input[i] == 'c') num *= 26;
            else{
                num *= 10;
            }
        }
        prev = input[i];
    }
    cout<<num<<endl;
    return 0;
}

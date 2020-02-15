//baekjoon 16968
//차량번호판 1
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

int main(void){
    string board;
    cin>>board;
    int sum = 1;
    int cc = 26;
    int dd = 10;
    int number = 0;
    //number 1 = d -> 2 = c
    for(int i = 0;i<board.size();i++){
        if(board.at(i) == 'c'){
            if(number == 2){
                sum *= cc-1;
            }
            else{
                sum *= cc;
                number =2;
            }
        }
        else{
            if(number ==1){
                sum*= dd-1;
            }
            else{
                sum *= dd;
                number = 1;
            }
        }
    }
    cout<<sum<<"\n";
}

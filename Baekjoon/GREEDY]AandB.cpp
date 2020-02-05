//baekjoon 12904
//A and B

//목표인 out의 뒤가 A이면 A 액션을 취했다는거고,B이면 B액션을 취했다는 거임.
//in out의 A B개수 차이로 A B액션의 횟수를 구하고 out를 백트래킹해서 구한 문자열이 in과
//같은지 확인하면 답을 구할 수 있다.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    string in, out;
    cin>>in;
    cin>>out;
    int a = 0;
    int b = 0;
    for(int i = 0;i<out.size();i++){
        if(out.at(i) == 'A') a++;
        else if(out.at(i) == 'B') b++;
    }
    for(int i = 0;i<in.size();i++){
        if(in.at(i) == 'A') a--;
        else if(in.at(i) == 'B') b--;
    }
    int n = a+b;
    for(int i = 0;i<n;i++){
        if(out.at(out.size()-1) == 'A'){
            a--;
            out.pop_back();
        }
        else if(out.at(out.size()-1) == 'B'){

            b--;
            out.pop_back();
            reverse(out.begin(), out.end());
   
        }
        if(a<0 || b<0){
            cout<<"0\n";
            return 0;
        }
    }
    
    if(in == out){
        cout<<"1";
    }
    else{
        cout<<"0";
    }

}
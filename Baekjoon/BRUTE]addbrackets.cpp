//baekjoon 16637
//괄호 추가하기
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int n;

struct term{
    int num;
    int op;
};

vector<int> bittovec(int bit){
    vector<int> bits;
    for(int i = 0;i<n/2;i++){
        bits.push_back(bit&1);
        bit >>=1;
    }
    return bits;
}

int main(void){
    
    cin>>n;
    string s;
    cin>>s;
    vector<term> array;
    for(int i = 0;i<n;i++){
        if(i%2 == 0){
            int num = s.at(i) - '0';
            array.push_back({num, 0});
        }
        else{
            int op = 1; //+
            if(s.at(i) == '-') op = 2;
            else if(s.at(i) == '*') op = 3;
            array.push_back({0, op});
        }
    }
    int m = (n-1)/2;
    int ans = INT_MIN;
    for(int i = 0;i<(1<<(m));i++){
        vector<int> brackets = bittovec(i);
        bool ok = true;
        for(int i = 0;i<n/2-1;i++){
            if(brackets[i] == 1 && brackets[i+1] == 1) ok = false;
        }
        if(!ok) continue;
        vector<term> b(array);
        for(int i = 0;i<(n-2);i+=2){
            if(brackets[i/2] == 1){
                if(b[i+1].op == 1){
                    b[i].num += b[i+2].num;
                    b[i+1].op = 0;
                    b[i+2].num = 0;
                }
                else if(b[i+1].op == 2){
                    b[i].num -= b[i+2].num;
                    b[i+1].op = 0;
                    b[i+2].num = 0;
                }
                else if(b[i+1].op == 3){
                    b[i].num *= b[i+2].num;
                    b[i+1].op = 0;
                    b[i+2].num = 0;
                }                
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout<<b[i].num<<" "<<b[i].op<<"\n";
        // }
        int partial = b[0].num;
        for(int i = 0;i<n;i+=2){
            if(b[i+1].op == 1) partial += b[i+2].num;
            else if(b[i+1].op == 2) partial -= b[i+2].num;
            else if(b[i+1].op == 3) partial *= b[i+2].num;
        }
        if(ans<partial) ans = partial;
        
    }
    cout<<ans<<"\n";

    
}
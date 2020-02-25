//baekjoon 16638
//괄호 추가하기 2
#include <iostream>
#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;
int n;
int multi[10];

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
            else if(s.at(i) == '*'){
                op = 3;
            } 
            array.push_back({0, op});
        }
    }
    int m = (n-1)/2;
    int ans = INT_MIN;
    for(int i = 0;i<(1<<(m));i++){
        vector<int> brackets = bittovec(i);
        bool ok = true;
        for(int j = 0;j<m-1;j++){
            if(brackets[j] == 1 && brackets[j+1] == 1) ok = false;
        }
        if(!ok) continue;
        vector<term> b(array);
        // for(int j = 0;j<m;j++){
        //     int k = 2*j+1;
        //     if(brackets[j] == 1){
        //         if(b[k].op == 1){
        //             b[k-1].num += b[k+1].num;
        //             b[k].op = -1;
        //             b[k+1].num = 0;
        //         }
        //         else if(b[k].op == 2){
        //             b[k-1].num -= b[k+1].num;
        //             b[k].op = -1;
        //             b[k+1].num = 0;
        //         }
        //         else if(b[k].op == 3){
        //             b[k-1].num *= b[k+1].num;
        //             b[k].op = -1;
        //             b[k+1].num = 0;
        //         }                
        //     }
        // }
        for(int j = 0;j<=b.size()-2;j=j+2){
            if(brackets[j/2] == 1){
                if(b[j+1].op == 1){
                    b[j].num += b[j+2].num;
                    b[j+1].op = -1;
                    b[j+2].num = 0;
                }
                else if(b[j+1].op == 2){
                    b[j].num -= b[j+2].num;
                    b[j+1].op = -1;
                    b[j+2].num = 0;
                }
                else if(b[j+1].op == 3){
                    b[j].num *= b[j+2].num;
                    b[j+1].op = -1;
                    b[j+2].num = 0;
                }                
            }
        }
        // for(int j = 0;j<n;j=j+2){
        //     if(j%2==0) cout<<b[j].num<<" ";
        // }
        // cout<<"\n";
        vector<term> c;
        for(int j = 0;j<b.size();j++){
            if(j%2==0){
                c.push_back(b[j]);
            }
            else{
                if(b[j].op == -1){
                    j++;
                }else{
                    if(b[j].op == 3){
                        int temp = c.back().num * b[j+1].num;
                        c.pop_back();
                        c.push_back({temp, 0});
                        j++;
                    }
                    else{
                        c.push_back(b[j]);
                    }
                }
            }
        }
        b = c;
        int partial = b[0].num;
        for(int j = 0;j<(b.size()-1)/2;j++){
            int k = j*2 +1;
            if(b[k].op == 1) partial += b[k+1].num;
            else if(b[k].op == 2) partial -= b[k+1].num;
        }
        if(ans<partial) ans = partial;
        
    }
    cout<<ans<<"\n";
}
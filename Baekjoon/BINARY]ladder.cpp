//baekjoon 2022
//사다리 https://www.acmicpc.net/problem/2022
#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

double y, x, c;

double findc(double d){
    double h1 = sqrt(pow(x, 2.0)-pow(d, 2.0));
    double h2 = sqrt(pow(y, 2.0)-pow(d, 2.0));
    double found = (h1 * h2)/(h1 + h2);
    return found;
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>y>>x>>c;
    double left = 0;
    double right = min(y, x);
    double ans = -1;

    while(abs(right-left)>1e-6){
        double  middle = (left+right)/2;
        double height = findc(middle);
        // cout<<left<<" "<<right<<" "<<middle<<" "<<can<<"\n";
        // if(abs(height - c) > 1e-6){
        //     ans = middle;
        //     break;
        // }
        if(height> c){
            ans = middle;
            left = middle;
        }
        else{
            right = middle;
        }
    }
    cout<<ans<<"\n";

    
    return 0;
}
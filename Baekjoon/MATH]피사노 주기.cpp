//baekjoon 9471
//피사노 주기

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long mod;

long long go(long long a, long long b)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a;
        }
        a = a * a;
        b /= 2;
    }
    return ans;
}

long long fisano(long long m){
    long long twos=0;
    long long fives = 0;
    while(m % 2 == 0){
        twos++;
        m/=2;
    }
    while(m % 5 == 0){
        fives++;
        m/=5;
    }
    long long ans = -1;
    if(m != 1) return ans;
    if(m == 1){
        if(twos == 1){
            if(fives >=1){
                ans = 6 * fives;
            }
            else{
                ans = 3;
            }
            return ans;
        }
        else if(twos > 1){
            if(twos == fives){
                ans = 15 * go(10, twos-1);
                return ans;
            }
            else if(fives == 0){
                ans = 3 * 1<<(twos-1);
                return ans;
            }
            
        }
        else if(fives>0){
            ans = 4 * go(5, fives);
            return ans;
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin>>p;
    while(p--){
        int id;
        cin>>id>>mod;
        long long m = mod;
        // long long ans = fisano(m);
        // if(ans != -1){
        //     cout<<id<<" "<<ans<<"\n";
        //     continue;
        // }
        long long first = 1;
        long long second = 1;
        for(long long i = 3;i<=mod*mod;i++){
            long long temp = second;
            second += first;
            second %= mod;
            first = temp % mod;
            if(first == 0 && second == 1){
                cout<<id<<" "<<i-1<<"\n";
                break;
            }
        }
    }
    return 0;
}

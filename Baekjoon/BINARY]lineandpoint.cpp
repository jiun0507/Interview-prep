
//baekjoon 11664
//선분과 점

#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

double ay, ax, az, by, bx, bz, cy, cx, cz;

double distance(double ay, double ax, double az, double by, double bx, double bz){
    return sqrt(pow(ay - by, 2.0) + pow(ax - bx, 2.0) + pow(az - bz, 2.0));
}


int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>ay>>ax>>az>>by>>bx>>bz>>cy>>cx>>cz;
    double left = 0.0;
    double right = 1.0;
    double dy = by-ay;
    double dx = bx-ax;
    double dz = bz-az;
    double m;
    while(true){
        if(abs(right - left)<1e-9){
            m = (right+left)/2;
            break;
        }
        
        double m1 = left + (right - left)/3;
        double m2 = right - (right - left)/3;
        double m1y = ay + dy*m1;
        double m1z = az + dz*m1;
        double m1x = ax + dx*m1;
        double m2x = ax + dx*m2;
        double m2y = ay + dy*m2;
        double m2z = az + dz*m2;
        double m1dist = distance(m1y, m1x, m1z, cy, cx, cz);
        double m2dist = distance(m2y, m2x, m2z, cy, cx, cz);
        if(m1dist<m2dist){
            right = m2;
        }
        else{
            left = m1;
        }
    }
    double my = ay + dy*m;
    double mz = az + dz*m;
    double mx = ax + dx*m;
    double dist = distance(my, mx, mz, cy, cx, cz);
    cout<<fixed<<setprecision(10)<<dist<<"\n";
    return 0;
}
//baekjoon 16937
//두 스티커
#include <iostream>
using namespace std;



int r[100], c[100];
int n;
int height, width;
bool check_range(int y, int x){
    return y<height && x<width&&y>=0&&x>=0;
}
int main(void){
    cin>>height>>width;
    cin>>n;
    for(int i =0 ;i<n;i++){
        cin>>r[i]>>c[i];
    }
    int mx = 0;
    for(int i = 0;i<n;i++){
        int y11 = r[i]-1; int x11 = c[i]-1;
        int y12 = c[i]-1; int x12 = r[i]-1;
        for(int j = 0;j<n;j++){
            if(i == j) continue;
            
            // cout<<y11<<" "<<x11<<" "<<y12<<" "<<x12<<"\n";
            int y21 = height - r[j]; int x21 = width - c[j];
            int y22 = height - c[j]; int x22 = width - r[j];
            // cout<<y21<<" "<<y12<<" "<<x21<<" "<<x12<<"\n";
            if((y21>y11 || x21>x11) &&check_range(y21, x21)&&check_range(y11, x11)) mx = max(mx, r[i]*c[i] + r[j]*c[j]); 
            if((y22>y11 || x22>x11)&&check_range(y22, x22)&&check_range(y11, x11)) mx = max(mx, r[i]*c[i] + r[j]*c[j]);
            if((y22>y12 || x22>x12)&&check_range(y22, x22)&&check_range(y12, x12)) mx = max(mx, r[i]*c[i] + r[j]*c[j]);
            if((y21>y12 || x21>x12)&&check_range(y21, x21)&&check_range(y12, x12)) mx = max(mx, r[i]*c[i] + r[j]*c[j]);
        }
        
    }
    cout<<mx<<"\n";
    // cout<<height<<" "<<width<<"\n";
    
}
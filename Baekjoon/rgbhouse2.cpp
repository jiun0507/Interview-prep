//baekjoon onetwothree 17404
//least price to paint n houses with rgb with given prices for painting
//rgb for ith house. First and last house is neighbour.
#include <iostream>
#include <algorithm>
using namespace std;

int price[1001][4]= {0};
int color[1001][4];
//if we paint nth house with i color. 
//the least money spent is price[n][i] = color[i] + min(price[n-1][i-1],price[n-1][i+1]);


void paint(int n){
	
	for(int i = 1;i<n;i++){
		price[i][1] = color[i][1] + min(price[i-1][2],price[i-1][3]);
		price[i][2] = color[i][2] + min(price[i-1][1],price[i-1][3]);
		price[i][3] = color[i][3] + min(price[i-1][1],price[i-1][2]);
	}
	return ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		for(int j = 1;j<=3;j++){ 
			cin>>color[i][j];
		}
	}
	
		
	int minim = 1000000;
	for(int i = 1; i<=3; i++){
		for(int j = 1;j<=3;j++){
			if(i == j){
				price[0][j] = color[0][j];
			}
			else{
				price[0][j] = 1001*1001;
			}
		}
		paint(n);
		if(i==1) minim = min(minim, min(price[n-1][2], price[n-1][3]));
		else if(i==2) minim = min(minim, min(price[n-1][1], price[n-1][3]));
		else if(i==3) minim = min(minim, min(price[n-1][1], price[n-1][2]));
		
	}
	cout<<minim<<"\n";
	return 0;

}
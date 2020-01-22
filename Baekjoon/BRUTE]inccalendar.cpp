//baekjoon 6064
//incan calendar with faster brute force 
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m >> n;
		int x, y;
		cin >> x >> y;
		x -= 1;
		y -= 1;
		
		int year = x;

		while(!( year % m == x && year % n == y) ){
			year += m;
			if(year > n*m){
				year = -2;
				break;
			}
		}
		cout<<++year<<"\n";
	}
    
 
	return 0;
}
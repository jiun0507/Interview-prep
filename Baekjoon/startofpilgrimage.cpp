//wallbreak4

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int p[2000], w[2000];
double memo[1020];
vector<vector<pair<double,double>>> check;

double calculate(vector<pair<double, double>> &d){
    double power, weight;
    power = weight = 0.0;
    for(int i = 0;i<d.size();i++){
        power += d[i].first;
        weight += d[i].second;
    }
    return power/weight;
}

void go(int index){
    if(index >= n){
        return;  
    } 
    double biggest = memo[index-1];
    // double biggest = 0.0 ;
    vector<pair<double,double>> ans;
    for(int j = 0;j<check.size();j++){
        // vector<pair<double,double>> d = check[j];
        // double d2 = calculate(d);
        // if(biggest < d2){
        //     ans = d;
        //     biggest =d2;
        // }
        for(int i =0;i<8;i++){
            vector<pair<double,double>> temp = check[j];
            temp[i] = (make_pair((double)p[index], (double)w[index]));

            double cur = calculate(temp);
            // printf("current value: %lf at index: %d\n", cur, index);
            // cout<<"index: "<<index<<" "<<cur<<" size of temp: "<<temp.size()<<"\n";
            if(biggest < cur){
                ans = temp;
                biggest =cur;
            }
        }
    }
    // for(int k = 0;k<8;k++){
    //     cout<<ans[k].first<<" "<<ans[k].second<<", ";
    // }   
    // cout<<"\n";
    memo[index] = biggest;
    check.push_back(ans);
    go(index+1);
    return;
    
}

int main(){
    scanf("%d\n", &n);
    vector<pair<double, double>> d;
	for(int i=0;i<n;i++){
		scanf("%d %d", &p[i], &w[i]);
// 		cout<<p[i]<<" "<<w[i]<<"\n";
	}
	for(int i = 0;i<8;i++){
	    d.push_back(make_pair((double)p[i], (double)w[i]));
	}

    double first = calculate(d);
	check.push_back(d);
	memo[7] = first;
// 	for(int j = 0;j<check.size();j++){
//         vector<pair<double,double>> ans = check[j];
//     	for(int i = 0;i<8;i++){
//             cout<<ans[i].first<<" "<<ans[i].second<<", ";
//         }   
//         cout<<"\n";
// 	}
    go(8);

	for(int i = 7;i<n;i++){
	    printf("%.9lf\n", memo[i]);
	}
// 	for(int j = 0;j<check.size();j++){
// 	    vector<pair<double,double>> ans = check[j];
//     	for(int i = 0;i<8;i++){
//             cout<<ans[i].first<<" "<<ans[i].second<<", ";
//         }   
//         cout<<"\n";
// 	}

// 	cout<<check.size()<<"\n";
    return 0;
}
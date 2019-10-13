#include <iostream>
#include <set>
using namespace std;

int main() {
	int n,sum;
	cin>>n;
	cin>>sum;
	set<int> s;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		s.insert(temp);
	}
	int array[n];
	for(int i=0;i<n;i++){
		cin>>temp;
		array[i] =temp; 
	}
	bool found = false;
	int diff=0;
	while(!found){
		
		for(int i=0;i<n;i++){
			set<int>::iterator it = s.find(sum-array[i]-diff);
			if(it!= s.end()){
				cout<<sum-diff<<endl;
				return 0;
			}
			it = s.find(sum-array[i]+diff);
			if(it!=s.end()){
				cout<<sum+diff<<endl;
				return 0;
			}
		}
		diff++;
	}
	
	return 0;
}

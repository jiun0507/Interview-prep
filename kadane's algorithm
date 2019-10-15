#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadane(int n, vector<int> array){
   
    int max_current=array[0];
    int max_global=array[0];
    for(int i=1;i<n;i++){
        max_current = max(max_current+array[i], array[i]);
        if(max_current>max_global){
            max_global= max_current;
        }
    }
    return max_global;
}

int main() {
    
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> array;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            array.push_back(temp);
        }
        
        int answer = kadane(n,array);
        cout<<answer<<endl;
    }
    
	//code
	return 0;
}

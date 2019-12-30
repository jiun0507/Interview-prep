#include <iostream>
using namespace std;

int stationNumber(int minute[], int train[][2], int n){
    
    for(int i=0;i<n;i++){
        int arrival = train[i][0];
        int departure = train[i][1];
        for(int j=arrival;j<=departure;j++){
            minute[j]+=1;
        }
    }
    int max = 0;
    for(int i = 0; i<2401;i++){
        if(minute[i]>max){
            max = minute[i];
        }
    }
    return max;
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int train[n][2];
    
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>train[j][i];
            }
        }
        
        int minute[2401];
        for(int i=0;i<2401;i++){
            minute[i]=0;
        }
        int stations = stationNumber(minute, train, n);
        cout<<stations<<endl;
        }
	//code
	return 0;
}

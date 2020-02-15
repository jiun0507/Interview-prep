//baekjoon 2343
//기타레슨
#include <iostream>
using namespace std;

int lessons[100001];
int n, m;
bool blueray(int length){
    int sum = lessons[0];
    int group = 1;
    for(int i = 1;i<n;i++){
        if(sum + lessons[i]>length){
            // cout<<sum<<"\n";
            sum = lessons[i];
            // cout<<sum<<"\n";
            group +=1;
        }
        else{
            sum += lessons[i];
        }
    }
    return group <=m;
}

int main(void){
    cin>>n>>m;
    int max = 0;
    int left= 0;
    int right = 0;
    for(int i = 0;i<n;i++){
        cin>>lessons[i];
        right += lessons[i];
        if(left<lessons[i]) left = lessons[i];
    }
    
    int ans;
    while(left<=right){
        int middle = (right+left)/2;
        if(blueray(middle)){
            ans = middle;
            right = middle -1;
        }
        else{
            left = middle + 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
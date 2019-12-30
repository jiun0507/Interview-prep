#include <iostream>
#include <utility>
using namespace std;

pair<int,int> subarray(int start, int end, int need, int array[],int n){
    
    
    //cout<<"need = "<<need<<endl;
    pair<int,int> noanswer;
    noanswer.first=-1;
    noanswer.second=-1;
    pair<int,int> answer;
    
    if(need ==0){
       // cout<<"end with "<<start<<" "<<end<<endl;
        answer.first =start;
        answer.second= end;
        return answer;
    }
    if(need>0){
        if(end+1 ==n){
            return noanswer;
        }
        return subarray(start, end+1, need-array[end+1],array,n);
    }
    if(need<0){
        int add = array[start];
        start+=1;
        if(start>end){
            if(start==n){
                return noanswer;
            }
            end+=1;
            return subarray(start, end, need+add-array[start],array,n);
        }
        return subarray(start, end, need+add,array,n);
    }
    
}

int main() {
    int t;
    cin>>t;
    int n,sum;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>sum;
        int array[n];
        int temp;
        for(int j=0;j<n;j++){
            cin>>temp;
            array[j] = temp;
        }
        pair<int,int> ans= subarray(0,0,sum-array[0],array,n);
        if(ans.first==-1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans.first+1<<" "<<ans.second+1<<endl;
        
    }

	return 0;
}

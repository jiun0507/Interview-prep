

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

const int mx = 1000000000;
string file_path = "output.txt";
ofstream writeFile(file_path.data());

void set1(){
    string response;
    bool found = false;
    for(int i = -5;i<=5;i++){
        for(int j = -5;j<=5;j++){
            cout<<i<<" "<<j<<endl;
            cout.flush();
            cin>>response;
            if(response=="CENTER"){
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(!found){
        cout<<1000000001<<" "<<1000000001<<endl;
        cout.flush();
    }
    return ;
}

int horizontal_binary(int left, int right, bool lower_bound){
    string response;
    int ans;
    while(left<=right){
        int middle = (right+left)/2;
        cout<<0<<" "<<middle<<endl;
        cout.flush();
        cin>>response;
        if(writeFile.is_open()){
            writeFile<<"Horizontal: "+to_string(middle)+" response: "+response<<"\n";
        }
        if(lower_bound){
            if(response=="HIT"){
                ans = middle;
                right = middle -1;
            }
            else if(response=="MISS"){
                left = middle + 1;
            }
        } else{
            if(response=="MISS"){
                ans = middle;
                right = middle -1;
            }
            else if(response=="HIT"){
                left = middle + 1;
            }
        }

    }
    if(writeFile.is_open()){
        writeFile<<"ans: "<<to_string(ans)<<"\n";
    }
    return ans;
}
int vertical_binary(int down, int up, bool lower_bound){
    string response;
    int ans;
    while(down<=up){
        int middle = (down+up)/2;
        cout<<middle<<" "<<0<<endl;
        cout.flush();
        cin>>response;
        if(writeFile.is_open()){
            writeFile<<"Vertical:"<<to_string(middle)+" response: "+response<<"\n";
            // writeFile.close();
        }
        if(lower_bound){
            if(response=="HIT"){
                ans = middle;
                up = middle -1;
            }
            else if(response=="MISS"){
                down = middle + 1;
            }
        } else{
            if(response=="MISS"){
                ans = middle;
                up = middle -1;
            }
            else if(response=="HIT"){
                down = middle + 1;
            }
        }
    }
    if(writeFile.is_open()){
        writeFile<<"ans:"<<to_string(ans)<<"\n";
        // writeFile.close();
    }
    return ans;
}


bool set2(){
    int hor_a, hor_b;
    hor_a = hor_b = mx+1;
    hor_a = horizontal_binary(-mx, -mx+110, true);
    hor_b = horizontal_binary(mx-110,mx, false);
    if(hor_a == mx+1||hor_b ==mx+1){
        return false;
    }
    int x = (hor_a+hor_b)/2;
    int vera, verb;
    vera=verb = mx+1;
    vera = vertical_binary(-mx, -mx+110, true);
    verb = vertical_binary(mx-110, mx, false);
    if(vera == mx+1||verb ==mx+1){
        return false;
    }
    string response;
    int y = (vera+verb)/2;
    if(writeFile.is_open()){
        writeFile<<"y and x:"<<to_string(y)<<" "<<to_string(x)<<"\n";
        // writeFile.close();
    }
    bool found = false;
    for(int i = x-3;i<=x+3;i++){
        for(int j = y-3;j<=y+3;j++){
            cout<<j<<" "<<i<<endl;
            cout.flush();
            cin>>response;
            if(writeFile.is_open()){
                writeFile<<"try:"<<to_string(j)<<" "<<to_string(i)<<" "<<response<<"\n";
                // writeFile.close();
            }
            if(response=="CENTER"){
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(found) return true;
    else{
        return false;
    }
}

int main()
{
    int t, a, b;
    cin>>t;
    cin>>a>>b;
    while(t--){
        bool result = set2();
        if(!result){
            return 0;
        }
    }
    return 0;
}

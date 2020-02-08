//baekjoon 2263
//트리의 순회
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int inorder[100000], postorder[100000], position[100010];
void solve(int inx , int iny, int postx, int posty){
    if(inx>iny || postx>posty) return;
    cout<<postorder[posty]<<" ";
    int middle = position[postorder[posty]];
    int left = middle- 1 -inx;
    int right = iny - middle;
    solve(inx, middle-1, postx, postx + left);
    solve(middle + 1, iny, postx + left + 1, posty-1);
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;

    for(int j = 0;j<n;j++){
        cin>>inorder[j];
        position[inorder[j]] = j;
    }
	for(int j = 0;j<n;j++){
	    cin>>postorder[j];
    }
    
    solve(0, n-1, 0, n-1);
    
    return 0;
}

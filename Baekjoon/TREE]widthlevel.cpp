//baekjoon 2250

//find the level with the largest width using inorder representation of tree

#include <iostream>

using namespace std;

int maxLengths[10001];//the index represents the level.
int minLengths[10001];
int length= 0;
int parent[10001];
struct Node{
	int left;
	int right;
};


Node a[10001];

void inorder(int node, int level){
	if(node == -1) return;
	inorder(a[node].left, level + 1);
	length ++;
	if(minLengths[level]>length){
		minLengths[level] = length;
	}
	if(maxLengths[level]<length){
		maxLengths[level] = length;
	}
	inorder(a[node].right, level + 1);
	return;
}


int main() {
	int n;
	cin>>n;
	
	for(int i = 0;i<n;i++){
		minLengths[i+1] = 10000;
		int x,y,z;
		cin>>x>>y>>z;
		if(y == -1){
			a[x].left = -1;
		}
		else{
			a[x].left = y;
			parent[y] +=1;
		}
		if(z == -1){
			a[x].right = -1;
		}
		else{
			a[x].right = z;
			parent[z] +=1;
		}
	}
	int root;
	for(int i = 1;i<=n;i++){
		if(parent[i] == 0){
			root = i;
			break;
		}
	}
	inorder(root, 1);
	int maxdiff = 0;
	int maxlevel;
	for(int i = 1;i<=n;i++){
		// cout<<"level: "<<i<<" "<<maxLengths[i]<<" "<<minLengths[i]<<"\n";
		int diff = maxLengths[i] - minLengths[i] + 1;
		if(maxdiff < diff){
			maxdiff = diff;
			maxlevel = i;
		}
	}
	cout<<maxlevel<<" "<<maxdiff<<"\n";
	return 0;
}
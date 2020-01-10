//baekjoon 1991
//basic tree question implementing preorder, inorder, postorder
#include <iostream>

using namespace std;

struct Node{
	int left;
	int right;
};

Node a[50];

void preorder(int node){
	if(node == -1) return;
	cout<<(char)(node + 'A');
	preorder(a[node].left);
	preorder(a[node].right);
	return;
}
void inorder(int node){
	if(node == -1) return;
	inorder(a[node].left);
	cout<<(char)(node + 'A');
	inorder(a[node].right);
	return;
}
void postorder(int node){
	if(node == -1) return;
	postorder(a[node].left);
	postorder(a[node].right);
	cout<<(char)(node + 'A');
	return;
}

int main() {
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		char x,y,z;
		cin>>x>>y>>z;
		x = x-'A';
		if(y == '.'){
			a[x].left = -1;
		}
		else{
			a[x].left = y-'A';
		}
		if(z == '.'){
			a[x].right = -1;
		}
		else{
			a[x].right = z- 'A';
		}
	}
	preorder(0);
	cout<<"\n";
	inorder(0);
	cout<<"\n";
	postorder(0);
	cout<<"\n";
	return 0;
}
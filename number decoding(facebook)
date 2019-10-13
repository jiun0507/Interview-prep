#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int recursion(const char* p, int n, int* dynamic){
	if(*p =='\0'){
		return 1;
	}
	if(dynamic[n]!=-1){
		return dynamic[n];
	}
	if(*p=='0'){
		return 0;
	}
	int count =0;
	
	count+=recursion(p+1,n+1, dynamic);
	if(*p-'0'<=2&&*(p+1)!='\0'&&*(p+1)-'0'<=6){
		count +=recursion(p+2,n+2,dynamic);
	}
	dynamic[n] = count;
	return count;
}

int main() {
	
	string mystring;
	getline(cin,mystring);
	int n = mystring.length();
	const char* array = (char*)malloc((n+1)*sizeof(char));
	int* dynamic = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		*(dynamic+i)= -1;
	}
	array = mystring.c_str();
	if(*(array+n-1)=='5'){
		cout<<"it works"<<'\n';
		
	}
	int recu = recursion(array, 0, dynamic);
	cout<<recu<<endl;
	return 0;
}

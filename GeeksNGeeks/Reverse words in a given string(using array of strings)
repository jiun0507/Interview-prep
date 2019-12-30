#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string unreversed;
        cin>>unreversed;
         //constant time
        int length = unreversed.length();
       
        int words=1;
        //complexity S
        for(int i=0;i<length;i++){
            if(unreversed.at(i)=='.'){
                words+=1;
            }
        }
        
        int wordLength = 0;
        int newWord = 0;
        char** stringArray = (char**) malloc(words * sizeof(char*));
        
        for(int i = 0; i <= length; i++){
            if(i == length ||unreversed.at(i)=='.'){
                
                *stringArray = (char*) malloc((wordLength + 1) * sizeof(char));
                char* sstring = *stringArray; 
                for(int j = 0; j < wordLength; j++){
                    *(sstring + j) = unreversed.at(i - wordLength + j);
                }
                *(sstring + wordLength) = '\0';
                wordLength = 0;
                stringArray+=1;
                
            }
            else{
                wordLength +=1;
            }
            
        }
        for(int i = 1; i <= words; i++){
            stringArray--;
            cout<<*stringArray;
            if(i != words){
                cout<<".";
            }
        }
        cout<<endl;
        for(int i = 0; i < words; i++){
           
            free(*(stringArray+i));
            
        }
        free(stringArray);
        
        
    }
	//code
	return 0;
}

class Solution {
public:
    int myAtoi(string s) {
        bool negative = false;
        long long ans = 0;
        int index = 0;
        while(true){
            if(s[index] == ' '){
                index++;
            } else{
                if((s[index]!='-' && s[index]!='+') && !(s[index] - '0' <=9 && '9' - s[index] <=9 )){
                    return 0;
                }
                break;
            }
        }
        if(s[index] == '-'){
            negative = true;
            index++;   
        } else if(s[index] == '+'){
            index++;
        }
        while(s[index] - '0' <=9 && '9' - s[index] <=9 ){
            ans *= 10;
            ans += s[index] - '0';
            if(ans > (long long)2147483647){
                if(negative){
                    ans = (-1)*ans;
                }
                if(ans >= (long long)2147483647){
                    return 2147483647;
                }
                if(ans<= (long long)-2147483648){
                    return -2147483648;
                }
            }
            index++;
            if(s.size() == index || s[index] == ' ' || !(s[index] - '0' <=9 && '9' - s[index] <=9 )){
                break;
            }
        }

        if(negative){
            ans = (-1)*ans;
        }
        return (int) ans;
    }
};
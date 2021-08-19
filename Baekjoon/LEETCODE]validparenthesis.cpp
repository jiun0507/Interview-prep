class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        int index = 0;
        int n = s.size();
        while(index<n){
            char cur = s[index];
            if(cur == '{' || cur == '(' || cur== '['){
                paren.push(cur);
            } else{
                if(paren.empty()) return false;
                char top = paren.top();
                if((cur=='}'&& top=='{') || (cur==']'&& top=='[') || (cur==')'&& top=='(')){
                    paren.pop();
                } else{
                    return false;
                }
            }
            index++;
        }
        if(paren.empty()) return true;
        return false;
    }
};
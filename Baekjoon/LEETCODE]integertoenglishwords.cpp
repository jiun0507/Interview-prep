class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string names[21] = {"", "One", "Two","Three","Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten","Eleven","Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen","Seventeen", "Eighteen", "Nineteen"};
        string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string chunks[4] = {"", "Thousand", "Million", "Billion"};
        string ret;
        int chunk_num = 0;
        while(num > 0){
            string cur;
            int hundred = (num % 1000) / 100;
            int ten = num % 100;
            if(hundred>0){
                cur += names[hundred] + " Hundred ";
            }
            if(ten<20 && ten>0){
                cur += names[ten] + " ";
            } else{
                if(ten!=0){
                    if(ten>=20) cur += tens[ten/10] + " ";
                    if(ten%10 !=0) cur += names[ten%10] + " ";
                }
            }
            if(ten>0 || hundred >0){
                if(chunk_num>0) cur += chunks[chunk_num] + " ";
            }
            ret.insert(0, cur);
            chunk_num++;
            num /= 1000;
        }
        cout<<ret;
        if(ret.back() == ' '){
            cout<<"works";
            ret.pop_back();
        }
        return ret;
    }
};
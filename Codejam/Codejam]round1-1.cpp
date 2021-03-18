// Codejam Round1 1. Pattern Matching 
// a check
// b check
// c check

/*
Find the longest prefix and suffix. Check if they contain all the other prefix and suffix(without *).
For the strings that are sandwhiched by the *, just concatenate them all and add to the middle. * will cover
any possible combination between.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct Pattern
{
    string real_pattern;
    string middle;
    int left;
    int right;
    Pattern(string real_pattern_, int left_, int right_) :
     real_pattern(real_pattern_), left(left_), right(right_) {}
};
bool cmp_left(Pattern &a, Pattern &b)
{

    return a.left>b.left;
}
bool cmp_right(Pattern &a, Pattern &b)
{
    return a.right>b.right;
}

pair<int,int> process_letters(string &unprocessed){
    int left = 0;
    for(auto c:unprocessed){
        if(c!='*') left++;
        else{
            break;
        }
    }
    int right = 0;
    for(int i = unprocessed.size()-1;i>=0;i--){
        if(unprocessed[i]!='*') right++;
        else{
            break;
        }
    }
    return make_pair(left, right);
}

string find_middle(string &whole, int left, int right){
    string middle = whole.substr(left, whole.size()-right);
    string ret = "";
    for(auto c:middle){
        if(c!='*'){
            ret += c;
        }
    }
    return ret;
}


int main()
{
    int t;
    cin>>t;
    int cnt = 1;
    while(t--){
        int n;
        cin>>n;
        cout<<"Case #"<<cnt++<<": ";
        vector<Pattern> left_picker;
        vector<Pattern> right_picker;
        string middle_total = "";
        for(int i = 0;i<n;i++){
            string buf;
            cin>>buf;
            auto letters = process_letters(buf);
            string middle = find_middle(buf, letters.first, letters.second);
            middle_total += middle;
            Pattern cur(buf, letters.first, letters.second);
            // cout<<buf<<" "<<letters.first<<" "<<letters.second<<"\n";
            left_picker.push_back(cur);
            right_picker.push_back(cur);
        }
        sort(left_picker.begin(), left_picker.end(), cmp_left);
        sort(right_picker.begin(), right_picker.end(), cmp_right);         
        
        Pattern left_p = left_picker[0];
        Pattern right_p = right_picker[0];
        string left_s = left_p.real_pattern.substr(0, left_p.left);
        string right_s = right_p.real_pattern.substr(right_p.real_pattern.size()-right_p.right, right_p.real_pattern.size());
        bool done = false;
        for(int i = 1;i<n;i++){
            string cur_left = left_picker[i].real_pattern;
            if(left_s.substr(0, left_picker[i].left)!=cur_left.substr(0, left_picker[i].left)){
                cout<<"*\n";
                done =true;
                break;
            }
        }
        if(done) continue;;
        for(int i = 1;i<n;i++){
            string cur_right = right_picker[i].real_pattern;
            int right = right_picker[i].right;
            cur_right = cur_right.substr(cur_right.size()-right, cur_right.size());
            if(right_s.substr(right_s.size()-right, right_s.size())!=cur_right){
                cout<<"*\n";
                done = true;
                break;
            }
        }
        if(done) continue;;

        cout<<left_s<<middle_total<<right_s<<"\n";
        
    }

    
    return 0;
}

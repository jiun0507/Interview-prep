class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0;
        int end = 0;
        int len = s.size();
        if(len==0) return 0;
        map<char, int> alp;
        alp[s[0]] = 1;
        int ret = 1;
        while(end < len){
            if(end==len-1) break;
            char next = s[end+1];
            if(alp[next]!=0){
                alp[s[begin]] = 0;
                begin++;
            } else{
                end++;
                alp[next] = 1;
                ret = max(ret, end - begin + 1);
            }
        }
        return ret;
    }
};

/* 
This is a mental note of data structures map, set, hash-map, and hash-set.
Hash is not sorted while non-hash DS is sorted. Map is a key, value pair DS that is 
essentially a Red-Black tree. Set only has key. It only contains unique keys. 
Since Map is a sorted DS, it takes lgN to search, add, and delete. Set also takes
lgN to search, add, and delete. They are both sorted. Thus, they can use lower_bound, 
upper_bound functions. 
Hash- is not sorted. It hashes the key to access the values. 
They merely an array that hash the key instead of using incremental indexes.Thus it takes a lot of memory.
It takes O(1) the time to hash the key to search, add, and delete. But they cannot be used for 
lower_bound, upper_bounds. It's a good idea to use hash DS if you do not want sorted DS.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> h;
        for(auto x:s) h[x]++;
        for(int i=0;i<s.length();i++){
            if(h[s[i]]==1) return i;
        }
        return -1;
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        unordered_map<string,int> mp;
        for(int i=0;i<=n-10;i++){
            string p=s.substr(i,10);
            mp[p]++;
        }
        vector<string> v;
        for(auto x:mp){
            if(x.second>1)
                v.push_back(x.first);
        }
        return v;
    }
};
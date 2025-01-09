class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) mp[nuts[i]]=i;
        
        for(int j=0;j<n;j++){
            if(nuts[j]!=bolts[j]){
                swap(bolts[mp[nuts[j]]],bolts[j]);
            }
        }
        
    }
};
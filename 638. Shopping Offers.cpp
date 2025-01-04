class Solution {
public:
    int f(vector<int>& pr, vector<vector<int>>& s, vector<int> n,map<vector<int>,int> &hmap){
        bool flag=1;
        for(int i=0;i<n.size();i++){
            if(n[i]!=0) flag=(flag & 0);
        }
        if(flag) return 0;
        if(hmap.find(n)!=hmap.end()) return hmap[n];

        int mn=INT_MAX;
        for(int i=0;i<s.size();i++){
            bool t=1;
            vector<int> c=n;
            for(int j=0;j<n.size();j++){
                   if(c[j]<s[i][j]) t=(t&0);
            }
            
            if(t){
                for(int k=0;k<n.size();k++){
                    c[k]=c[k]-s[i][k];
                }
                mn=min(mn,s[i][n.size()]+f(pr,s,c,hmap));
            } 
        }
        int r=0;
        for(int i=0;i<n.size();i++){
            r+=n[i]*pr[i];
        }
        mn=min(mn,r);
        return hmap[n]=mn;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>,int> hmap;
        return f(price,special,needs,hmap);
    }
};
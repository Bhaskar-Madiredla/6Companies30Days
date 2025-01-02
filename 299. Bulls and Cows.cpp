class Solution {
public:
    string getHint(string s, string g) {
        int n=s.length();
        int a=0,b=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]-'0']++;
        }

        for(int i=0;i<n;i++){
            if(s[i]==g[i]) a++;
            if(mp.find(g[i]-'0')!=mp.end() && mp[g[i]-'0']>0){ 
                b++;
                mp[g[i]-'0']--;
                if(mp[g[i]-'0']==0) mp.erase(g[i]-'0');
            }
        }
        return to_string(a)+"A"+to_string(b-a)+"B";
    }
};
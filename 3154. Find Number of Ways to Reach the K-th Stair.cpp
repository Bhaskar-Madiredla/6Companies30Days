class Solution {
public:
    unordered_map<string,int> dp;

    int f(int i,int last,int j,int k){
        if(i==k && j>2) return 1;
        if(i>k+1) return 0;
        string s=to_string(i)+" "+to_string(last)+" "+to_string(j);
        if(dp.find(s)!=dp.end()) return dp[s];
        int cnt=i==k;
        if(i>0 && last==1){
            cnt+=f(i-1,0,j,k);
        }
        cnt+=f(i+(1<<j),1,j+1,k);
        return dp[s]=cnt;
    }

    int waysToReachStair(int k) {
        dp.clear();
        return f(1,1,0,k);
    }
};

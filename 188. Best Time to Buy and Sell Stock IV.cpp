class Solution {
public:
    int f(vector<int>& prs,int i,int buy,int k,int n,vector<vector<vector<int>>> &dp){
        if(i>=n || k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int mx=0;
        if(buy) mx=max(-prs[i]+f(prs,i+1,0,k,n,dp),0+f(prs,i+1,1,k,n,dp));
        else mx=max(prs[i]+f(prs,i+1,1,k-1,n,dp),0+f(prs,i+1,0,k,n,dp));
        return dp[i][buy][k]=mx;
    }

    int maxProfit(int k, vector<int>& prs) {
        int n=prs.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(prs,0,1,k,n,dp);
    }
};
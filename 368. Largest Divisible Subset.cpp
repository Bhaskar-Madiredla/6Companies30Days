class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),maxi=1,last=0;
        vector<int> dp(n,1),hash(n),res;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if((nums[i]%nums[prev]==0) && (dp[i]<dp[prev]+1)){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        res.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            res.push_back(nums[last]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
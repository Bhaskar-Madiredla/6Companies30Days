class Solution {
public:
    int n;

    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        long long cnt=INT_MAX;
        vector<long long> v(n,0);
        v[0]=nums[0];
        for(int i=1;i<n;i++){
            v[i]=(v[i-1]+nums[i]);
        }

        for(int i=0;i<n;i++){
            cnt=min(cnt,(v[n-1]-v[i]-(n-1-i)*1LL*nums[i]) + ((i+1)*1LL*nums[i]-v[i]));
        }
        return cnt;
    }
};
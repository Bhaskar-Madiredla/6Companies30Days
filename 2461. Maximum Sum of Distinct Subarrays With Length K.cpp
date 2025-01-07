class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long res=0,sum=0;
        unordered_map<int,int> hmap; 
        for(int i=0;i<k;i++){
            sum+=nums[i];
            hmap[nums[i]]++;
        }
        if(hmap.size()==k) res=max(res,sum);
        for(int i=k;i<n;i++){
            sum+=(nums[i]-nums[i-k]);
            hmap[nums[i]]++;
            hmap[nums[i-k]]--;
            if(hmap[nums[i-k]]==0)
                hmap.erase(nums[i-k]);
            if(hmap.size()==k) 
                res=max(res,sum);
        }
        return res;
    }
};
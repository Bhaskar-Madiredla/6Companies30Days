class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0,n=nums.size(),ocnt=0;
        unordered_map<int,int> hmap;
        hmap[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) ocnt++;
            if(hmap.find(ocnt-k)!=hmap.end()){
                cnt+=hmap[ocnt-k];
            }
            hmap[ocnt]++;
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v,q;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=n-1;i>n-1-k;i--){
            q.push_back({v[i].second,v[i].first});
        }
        sort(q.begin(),q.end());
        vector<int> res;
        for(auto x : q) res.push_back(x.second);
        return res;
    }
};
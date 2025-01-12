class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int> v(n);
        int j=0;
        int i=1;
        for(;i<n;i+=2){
            v[i]=nums[j];
            j++;
        }
        i=0;
        for(;i<n;i+=2){
            v[i]=nums[j];
            j++;
        }
        nums=v;
    }
};
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int curr=0,mx=0,n=arr.size();
        bool f=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){ 
                if(!f) curr++;
                else{ f=0; curr=1;}
            }
            else{
                if(curr>0 && arr[i]<arr[i-1]){
                    curr++;
                    mx=max(mx,curr+1);
                    f=1;
                }
                else curr=0;
            }
        }
        return mx;
    }
};
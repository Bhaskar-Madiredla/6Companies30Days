class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        int n=arr.size();
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[dq.front()]<=arr[i]){
                dq.pop_front();
            }
            dq.push_front(i);
        }
        res.push_back(arr[dq.back()]);
        for(int i=k;i<n;i++){
            while(!dq.empty() && arr[dq.front()]<=arr[i]){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back()<=i-k){
                dq.pop_back();
            }
            dq.push_front(i);
            res.push_back(arr[dq.back()]);
        }
        return res;
    }
};
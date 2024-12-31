class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }

    int maxEnvelopes(vector<vector<int>>& ev) {
        sort(ev.begin(),ev.end(),cmp);
        vector<int> lis;
        for(int i=0;i<ev.size();i++){
            if(lis.empty() || lis.back()<ev[i][1]) lis.push_back(ev[i][1]);
            else{
                int inx=lower_bound(lis.begin(),lis.end(),ev[i][1])-lis.begin();
                lis[inx]=ev[i][1];
            }
        }
        return lis.size();
    }
};